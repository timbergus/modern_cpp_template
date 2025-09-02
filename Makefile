BUILD=build
BUILD_TYPE ?= debug
PROJECT=modern_cpp_template

# To execute it with a different value you can use make BUILD_TYPE=release
init:
	cmake --preset=$(BUILD_TYPE)

project: init
	cmake --build $(BUILD)

start: project
	./$(BUILD)/$(PROJECT)

documentation: project
	cmake --build $(BUILD) --target ${PROJECT}_docs

test: project
	ctest --test-dir $(BUILD)

package: project documentation
	cpack -G ZIP --config $(BUILD)/CPackConfig.cmake

clean:
	rm -rf $(BUILD) .cache docs _CPack* *.zip Testing
