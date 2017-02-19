# Add inputs and outputs from these tool invocations to the build variables 
OUTPUT_DIR = bin/
SLICKTORRENT = $(OUTPUT_DIR)SlickTorrent
OBJS_DIR = obj/
MAIN = $(OBJS_DIR)main.o
BENCODER = $(OBJS_DIR)BencodeValue.o
BENCODERDICT = $(OBJS_DIR)BencodeDictionary.o
BENCODESTRING = $(OBJS_DIR)BencodeString.o
BENCODEINTEGER = $(OBJS_DIR)BencodeInteger.o
CXX = clang++ -std=c++11 -stdlib=libc++
CXX_FLAGS = -Wall -g -c
OBJS = $(MAIN) $(BENCODER) $(BENCODERDICT) $(BENCODESTRING) $(BENCODEINTEGER)
DEPENDENCIES = $(BENCODER) $(BENCODERDICT) $(BENCODESTRING) $(BENCODEINTEGER)
VPATH = src


# All Target
all: build $(SLICKTORRENT)

build:
	mkdir -p $(OUTPUT_DIR)
	mkdir -p $(OBJS_DIR)
	cp -f puppy.torrent $(OUTPUT_DIR)

# Tool invocations
$(SLICKTORRENT): $(MAIN)
	@echo 'Building target: $@'
	@echo 'Invoking: MacOS X C++ Linker'
	$(CXX) -g $(OBJS) -o $(SLICKTORRENT)
	@echo 'Finished building target: $@'
	@echo ' '

$(MAIN): main.cpp $(DEPENDENCIES)
	$(CXX) $(CXX_FLAGS) $< -o $@

$(BENCODER): BencodeValue.cpp BencodeValue.h
	$(CXX) $(CXX_FLAGS) $< -o $@

$(BENCODERDICT): BencodeDictionary.cpp BencodeDictionary.h $(BENCODER)
	$(CXX) $(CXX_FLAGS) $< -o $@

$(BENCODESTRING): BencodeString.cpp BencodeString.h $(BENCODER)
	$(CXX) $(CXX_FLAGS) $< -o $@

$(BENCODEINTEGER): BencodeInteger.cpp BencodeInteger.h $(BENCODER)
	$(CXX) $(CXX_FLAGS) $< -o $@

# Other Targets
.PHONY: clean
clean:
	-rm -r $(OUTPUT_DIR)
	-rm -r $(OBJS_DIR)
	-@echo ' '
