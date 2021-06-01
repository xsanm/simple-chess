cmake_minimum_required(VERSION 3.19)
project(simple_chess)

include_directories("/images/")

set(CMAKE_CXX_STANDARD 14)
find_package(SFML 2.5.1 COMPONENTS system graphics audio network REQUIRED)
add_executable (simple-chess "main.cpp" src/GameEngine.cpp src/GameEngine.h src/ChessPiece.cpp src/ChessPiece.h src/BoardVector.cpp src/BoardVector.h src/Board.cpp src/Board.h src/Pieces/Pawn.cpp src/Pieces/Pawn.h src/Pieces/Knight.cpp src/Pieces/Knight.h src/Pieces/Queen.cpp src/Pieces/Queen.h src/Pieces/Bishop.cpp src/Pieces/Bishop.h src/Pieces/Rook.cpp src/Pieces/Rook.h src/Pieces/King.cpp src/Pieces/King.h src/Data.h src/Connector.cpp src/Connector.h)
target_link_libraries(simple-chess  PRIVATE sfml-audio sfml-graphics sfml-network sfml-system)


