# Boardgames

* framework with piece / field association, move list, engine and UI
* Mühle (German name for nine Men's Morris or Mill)


# Directory Structure

The top level structure follows [the pitchfork layout](https://api.csswg.org/bikeshed/?force=1&url=https://raw.githubusercontent.com/vector-of-bool/pitchfork/develop/data/spec.bs).


## `src/`

The framework parts are located in the directories `boardgame/` and `boardgam_qml/`.
The game "Mühle" resides in `muehle` and `muehle_qml`.


## `tests/`

Unit tests are [placed separately](https://api.csswg.org/bikeshed/?force=1&url=https://raw.githubusercontent.com/vector-of-bool/pitchfork/develop/data/spec.bs#src.tests.separate) from their sources, because measuring test coverage becomes incorrect if the test resides in the same directory as the source files. Test code coverage is of course 100%, so the overall coverage would look better than it is. Namig unit test files is done as described in the pitchfork paragraph [Merged Test Placement](https://api.csswg.org/bikeshed/?force=1&url=https://raw.githubusercontent.com/vector-of-bool/pitchfork/develop/data/spec.bs#src.tests.merged)

The directories whose names match a directory name from `src/` contain unit tests.


## `data/`

Contins graphics files and a valgrind memcheck suppression file `memcheck.supp`


## `docs/`

Changelog.md and UML diagrams


# Build Requirements

* C++ 17 toolchain
* cmake >= 3.5.1
* Qt >= 5.11 with Qml


# Optional Tools

* [Umlet](https://www.umlet.com) UML Editor (*.uxf files in /docs)

# Included Resources

CMake file AddGoogleTest.cmake adapted from https://github.com/CLIUtils/cmake/blob/master/AddGoogleTest.cmake 4e52e4d is licensed under a [BSD 3-Clause License](https://github.com/CLIUtils/cmake/blob/master/LICENSE): changed GIT_TAG to release-1.8.1

CMake file CodeCoverage.cmake adapted from https://github.com/bilke/cmake-modules/blob/master/CodeCoverage.cmake 7727aa7 is licensed under a BSD 3-Clause License included in the file itself: commented out `COMMAND ${LCOV_PATH} --gcov-tool ${GCOV_PATH} --remove ${Coverage_NAME}.total ${COVERAGE_LCOV_EXCLUDES} ...` and added `COMMAND ${LCOV_PATH} --gcov-tool ${GCOV_PATH} --extract ${Coverage_NAME}.total ${COVERAGE_LCOV_INCLUDES} ...`

CMake files [DownloadProject.CMakeLists.cmake.in](https://github.com/Crascit/DownloadProject/blob/master/DownloadProject.CMakeLists.cmake.in) 8adf965 and [DownloadProject.cmake](https://github.com/Crascit/DownloadProject/blob/master/DownloadProject.cmake) 26983dd are licensed under [MIT License](https://github.com/Crascit/DownloadProject/blob/master/LICENSE).

Icons adapted from [tiddlywiki](https://tiddlywiki.com) 5.1.17 are licensed under a [BSD 3-Clause License](https://tiddlywiki.com/#License): added `version="1.1" xmlns="http://www.w3.org/2000/svg"` to svg tag

* back.svg ([$:/core/images/left-arrow](https://tiddlywiki.com/#%24%3A%2Fcore%2Fimages%2Fleft-arrow))
* delete.svg ([$:/core/images/delete-button](https://tiddlywiki.com/#%24%3A%2Fcore%2Fimages%2Fdelete-button))
* export.svg ([$:/core/images/unfold-button](https://tiddlywiki.com/#%24%3A%2Fcore%2Fimages%2Funfold-button))
* forward.svg ([$:/core/images/right-arrow](https://tiddlywiki.com/#%24%3A%2Fcore%2Fimages%2Fright-arrow))
* hide.svg ([$:/core/images/preview-closed](https://tiddlywiki.com/#%24%3A%2Fcore%2Fimages%2Fpreview-closed))
* home.svg ([$:/core/images/home-button](https://tiddlywiki.com/#%24%3A%2Fcore%2Fimages%2Fhome-button))
* import.svg ([$:/core/images/fold-button](https://tiddlywiki.com/#%24%3A%2Fcore%2Fimages%2Ffold-button))
* list.svg ([$:/core/images/list-bullet](https://tiddlywiki.com/#%24%3A%2Fcore%2Fimages%2Flist-bullet))
* refresh.svg ([$:/core/images/refresh-button](https://tiddlywiki.com/#%24%3A%2Fcore%2Fimages%2Frefresh-button))
* setup.svg ([$:/core/images/copy-clipboard](https://tiddlywiki.com/#%24%3A%2Fcore%2Fimages%2Fcopy-clipboard))
* show.svg ([$:/core/images/preview-open](https://tiddlywiki.com/#%24%3A%2Fcore%2Fimages%2Fpreview-open))

Icon taken from [openclipart](https://openclipart.com) is licensed under [Creative Commons Zero 1.0 Public Domain License](https://openclipart.org/share):

* engine.svg ([Wireframe-Head.svg](https://openclipart.org/detail/275796/wireframe-head)): changed stroke-width to 19.0665, set width and height to 22pt
