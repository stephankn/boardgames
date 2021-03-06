#ifndef SRC_MUEHLE_QML_MUEHLE_QML
#define SRC_MUEHLE_QML_MUEHLE_QML

#include "boardgame/boardgame_ui.h"
#include "muehle/muehle_state.h"
#include "boardgame_qml/multi_move_list_qml.h"
#include "boardgame/main_loop.h"

#include <QObject>
#include <QQmlComponent>
#include <QQuickItem>
#include <QQmlProperty>
#include <QSettings>

#include <memory>
#include <vector>
#include <future>
#include <chrono>

class QQmlEngine;

namespace muehle_qml
{

class Muehle_Qml
        : public QObject
{
    Q_OBJECT
public:
    Muehle_Qml(QQmlEngine* engine, QQuickItem* parentItem);

    // Boardgame_Ui functions
    friend void draw(Muehle_Qml* mui);
    friend void win(Muehle_Qml* mui, const std::string& player);
    friend void drawer_can_hide(Muehle_Qml* ui, const std::string& player_id, const bool can_hide) { ui->board_property(player_id + "_drawer_can_hide").write(can_hide); }
    friend void prison_can_hide(Muehle_Qml* ui, const std::string& player_id, const bool can_hide) { ui->board_property(player_id + "_prison_can_hide").write(can_hide); }
    friend void lock_piece(Muehle_Qml* ui, const boardgame::Piece_Number pieceId) { QQmlProperty(ui->pieces.at(static_cast<std::size_t>(pieceId.v)).get(), "state").write("lock"); }
    friend void selectable(Muehle_Qml* ui, const boardgame::Piece_Number pieceId) { QQmlProperty(ui->pieces.at(static_cast<std::size_t>(pieceId.v)).get(), "state").write("selectable"); }
    friend void removable(Muehle_Qml* ui, const boardgame::Piece_Number pieceId) { QQmlProperty(ui->pieces.at(static_cast<std::size_t>(pieceId.v)).get(), "state").write("removable"); }
    friend void lock_field(Muehle_Qml* ui, const boardgame::Field_Number fieldId) { QQmlProperty(ui->fields.at(static_cast<std::size_t>(fieldId.v)).get(), "state").write(""); }
    friend void highlight(Muehle_Qml* ui, const boardgame::Field_Number fieldId) { QQmlProperty(ui->fields.at(static_cast<std::size_t>(fieldId.v)).get(), "state").write("highlight"); }
    friend void occupiable(Muehle_Qml* ui, const boardgame::Field_Number fieldId, boardgame::Piece_Number pieceId);
    friend void set_field(Muehle_Qml* ui, const boardgame::Piece_Number pieceId, const boardgame::Field_Number fieldId) { QQmlProperty(ui->pieces.at(static_cast<std::size_t>(pieceId.v)).get(), "next_parent").write(QVariant::fromValue(ui->fields.at(static_cast<std::size_t>(fieldId.v)).get()->parentItem())); }
    friend void setup_mode_active(const Muehle_Qml* ui, const bool is_active) { QQmlProperty(ui->control.get(), "setup_mode_active").write(is_active); }
    friend void engine_active(const Muehle_Qml* ui, const std::string& player_id, const bool is_active) { QQmlProperty(ui->control.get(), (player_id + "_engine_active").c_str()).write(is_active); }
    friend void active_player(const Muehle_Qml* ui, const std::string& player_id);
    friend void need_confirm(Muehle_Qml* ui, const bool is_needed) { QQmlProperty(ui->control.get(), "confirm").write(is_needed); }

    // Main_Loop functions
    friend void engine_future(Muehle_Qml* ml, std::future<bool>&& efu) { ml->wait_for_engine_move(std::move(efu)); }
    friend void set_main_loop_engine_time(Muehle_Qml* ml, std::chrono::seconds time_in_s) { ml->engine_time = time_in_s; }

signals:
    void engine_move(bool);
    void force_engine_move();
private slots:
    void new_game() { muehle_state.new_game(); }
    void request_white_engine_active(bool is_active) { muehle_state.request_engine_active(muehle::white_id, is_active); }
    void request_black_engine_active(bool is_active) { muehle_state.request_engine_active(muehle::black_id, is_active); }
    void request_setup_mode_active(bool is_active) { muehle_state.request_setup_mode_active(is_active); }
    void removed(int p_id) { muehle_state.piece_removed(boardgame::Piece_Number{p_id}); }
    void selected(int p_id) { muehle_state.request_select_piece(boardgame::Piece_Number{p_id}); }
    void occupy(int f_id) { muehle_state.request_occupy(boardgame::Field_Number{f_id}); }
    void engine_depth(int depth);
    void engine_time_in_s(int time_in_s);
    void white_color_changed(QString new_white_color);
    void black_color_changed(QString new_black_color);
    void use_main_field();
    void use_alternative_field();
private:
    QQmlProperty board_property(const std::string& property_name) { return QQmlProperty(board.get(), QString(property_name.c_str())); }
    QQuickItem* board_item(const std::string& item_name) { return board_property(item_name).read().value<QQuickItem*>(); }
    void read_settings();
    void write_settings();
    void wait_for_engine_move(std::future<bool>&& efu);
    void color_change(const std::string& color_property_name, const QString& player_active_property_name, const QString& new_color,  boardgame::Piece_Number first_piece, boardgame::Field_Number first_prison_field);
    muehle::Muehle_State muehle_state;
    QQmlComponent control_component;
    std::unique_ptr<QQuickItem> control;
    std::unique_ptr<QQuickItem> board;
    QQmlComponent piece_component;
    std::vector<std::unique_ptr<QQuickItem>> pieces;
    QQmlComponent field_component;
    std::vector<std::unique_ptr<QQuickItem>> fields;
    boardgame_qml::Multi_Move_List_Qml move_lists;
    static constexpr std::chrono::seconds engine_time_default {9999};
    std::chrono::seconds engine_time {engine_time_default};
    QSettings settings;
    static constexpr char engine_mode_time[] = "engine_mode_time";
    static constexpr char engine_mode_depth[] = "engine_mode_depth";
    QString engine_mode;
};

}

#endif // SRC_MUEHLEQML_MUEHLEQML
