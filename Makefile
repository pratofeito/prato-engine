file := demo

.phony: run, install

install:
	cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
	cmake --build build

run: install
	./$(file)
