cmake_minimum_required(VERSION 3.12)
project(dna)

set(CMAKE_CXX_STANDARD 98)

add_executable(dna main.cpp model/DnaSequence.h model/DnaSequence.cpp model/DnaReaderText.cpp model/DnaReaderText.h model/DnaWriter.cpp model/DnaWriter.h model/DnaData.cpp model/DnaData.h view/Cmd.cpp view/Cmd.h view/CommandParser.cpp view/CommandParser.h controller/Controller.cpp controller/Controller.h controller/FactoryCommand.cpp controller/Command.cpp model/Idna.h controller/New.cpp controller/New.h controller/Command.h controller/FactoryCommand.h view/UI.h model/DnaMetaData.cpp model/DnaMetaData.h controller/Load.cpp controller/Load.h model/Nucleotide.cpp model/Nucleotide.h controller/Save.cpp controller/Save.h controller/Show.cpp controller/Show.h)
