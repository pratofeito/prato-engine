file := demo

.phony: run, install

install:
	cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
	cmake --build build
	mv build/application build/$(file)
	mv build/$(file) ./

run: install
	./$(file)
