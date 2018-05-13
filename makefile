# Add inputs and outputs from these tool invocations to the build variables 
OUTPUT_DIR = bin/
SLICKTORRENT = $(OUTPUT_DIR)SlickTorrent
OBJS_DIR = obj/
MAIN = $(OBJS_DIR)main.o
BENCODER = $(OBJS_DIR)BencodeValue.o
BENCODERDICT = $(OBJS_DIR)BencodeDictionary.o
BENCODESTRING = $(OBJS_DIR)BencodeString.o
BENCODEINTEGER = $(OBJS_DIR)BencodeInteger.o
BENCODELIST = $(OBJS_DIR)BencodeList.o
BENCODEPARSER = $(OBJS_DIR)BencodeParser.o
CXX = clang++ -std=c++11 -stdlib=libc++ -Wc++11-extensions
CXX_FLAGS = -Wall -g -c
LD_LIBS =
LD_FLAGS =
OBJS = $(MAIN) $(BENCODER) $(BENCODERDICT) $(BENCODESTRING) $(BENCODEINTEGER) $(BENCODELIST) $(BENCODEPARSER)
VPATH = src


# All Target
all: build $(SLICKTORRENT)

build:
	mkdir -p $(OUTPUT_DIR)
	mkdir -p $(OBJS_DIR)
	cp -f *.torrent $(OUTPUT_DIR)

# Tool invocations
$(SLICKTORRENT): $(MAIN)
	@echo 'Building target: $@'
	@echo 'Invoking: MacOS X C++ Linker'
	$(CXX) -g $(OBJS) -o $(SLICKTORRENT)
	@echo 'Finished building target: $@'
	@echo ' '

$(MAIN): main.cpp $(BENCODER) $(BENCODERDICT) $(BENCODESTRING) $(BENCODEINTEGER) $(BENCODELIST) $(BENCODEPARSER)
	$(CXX) $(CXX_FLAGS) $< -o $@

$(BENCODER): Bencode/BencodeValue.cpp Bencode/BencodeValue.h
	$(CXX) $(CXX_FLAGS) $< -o $@

$(BENCODERDICT): Bencode/BencodeDictionary.cpp Bencode/BencodeDictionary.h $(BENCODER)
	$(CXX) $(CXX_FLAGS) $< -o $@

$(BENCODESTRING): Bencode/BencodeString.cpp Bencode/BencodeString.h $(BENCODER)
	$(CXX) $(CXX_FLAGS) $< -o $@

$(BENCODEINTEGER): Bencode/BencodeInteger.cpp Bencode/BencodeInteger.h $(BENCODER)
	$(CXX) $(CXX_FLAGS) $< -o $@

$(BENCODELIST): Bencode/BencodeList.cpp Bencode/BencodeList.h $(BENCODER)
	$(CXX) $(CXX_FLAGS) $< -o $@

$(BENCODEPARSER): Bencode/BencodeParser.cpp Bencode/BencodeParser.h $(BENCODER) $(BENCODERDICT) $(BENCODESTRING) $(BENCODEINTEGER) $(BENCODELIST)
	$(CXX) $(CXX_FLAGS) $< -o $@

# Other Targets
.PHONY: clean
clean:
	-rm -r $(OUTPUT_DIR)
	-rm -r $(OBJS_DIR)
	-@echo ' '
