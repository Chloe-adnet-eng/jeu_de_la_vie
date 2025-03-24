SRC_DIR = src
BUILD_DIR = build

compile:
	clang++ $(SRC_DIR)/$(fichier).cpp -o $(BUILD_DIR)/$(fichier)

execute:
	./$(BUILD_DIR)/$(fichier_compile)