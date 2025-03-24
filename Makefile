compile:
	cmake -B build
	cmake --build build

execute:
	./build/bin/main

compile_and_execute:
	$(MAKE) compile
	$(MAKE) execute
