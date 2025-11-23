.PHONY: run configure compile clean rebuild

# Directory for build artifacts
BUILD_DIR := build

# Path to the executable
APP := $(BUILD_DIR)/app_fixtures
APP_CPP := $(BUILD_DIR)/app_cpputest

run: $(APP) $(APP_CPP)
	@echo "Running application..."
	@$(APP)
	@$(APP_CPP)

configure:
	@echo "Configuring CMake..."
	cmake -B $(BUILD_DIR)

compile: configure
	@echo "Building project..."
	cmake --build $(BUILD_DIR)

# Rebuild everything from scratch
rebuild: clean compile

# Create the binary by compiling
$(APP): 
	$(MAKE) compile

$(APP_CPP): 
	$(MAKE) compile

# Cleaning
clean:
	@echo "Cleaning build directory..."
	@rm -rf $(BUILD_DIR)
