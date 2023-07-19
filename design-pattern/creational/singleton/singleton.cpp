#include <map>
#include <string>

class GlobalCoffeeConfig {
    std::map<std::string, std::string>  coffeeState;

    // Private constructor
    GlobalCoffeeConfig() {}

    public:
    // Remove ability to use the copy constructor
    GlobalCoffeeConfig(GlobalCoffeeConfig const&) = delete;

    // Remove ability to use the copy assignment operator
    GlobalCoffeeConfig& operator=(GlobalCoffeeConfig const&) = delete;

    // Provide a single, static method for retriving the singleton instance
    static GlobalCoffeeConfig &get() {
        static GlobalCoffeeConfig config;
        return config;
    }

    void setState( const std::string &key, const std::string &value ) {
        auto iterator = coffeeState.find(key);
        if( iterator != coffeeState.end() ){
            iterator->second = value;
        }
        else{
            coffeeState.insert({ key, value });
        }
    }

    std::string getState( const std::string &key ) {
        auto iterator = coffeeState.find(key);
        return iterator->second;
    }

    ~GlobalCoffeeConfig() { printf("** dtor **\n"); }

};

void someFunction(){

    printf("** someFunction **\n");
    GlobalCoffeeConfig& configObj = GlobalCoffeeConfig::get();
    configObj.setState("COFFEE_STATUS", "OFF");
    printf("COFFEE_STATUS: %s\n", configObj.getState("COFFEE_STATUS").c_str());
    printf("COFFEE_HEALTH_URL: %s\n", configObj.getState("COFFEE_HEALTH_URL").c_str());
    printf("SOME_COFFEE: %s\n", configObj.getState("SOME_COFFEE").c_str());
}

int main() {
    // Can't compile this line because the constructor is private
    //GlobalCoffeeConfig configObj = GlobalCoffeeConfig();

    // The "get" method is the only way to retrive the static, singleton instance
    // This line doesn't compile, because the copy constructor has been removed - a new instance cannot be created
    // GlobalCoffeeConfig configObj = GlobalCoffeeConfig::get();
    GlobalCoffeeConfig& configObj = GlobalCoffeeConfig::get();

    configObj.setState("COFFEE_STATUS", "ON");
    configObj.setState("COFFEE_HEALTH_URL", "./health");

    printf(" ** main **\n");
    printf("COFFEE_STATUS: %s\n", configObj.getState("COFFEE_STATUS").c_str());
    printf("COFFEE_HEALTH_URL: %s\n", configObj.getState("COFFEE_HEALTH_URL").c_str());

    someFunction();

    printf(" ** main **\n");
    printf("COFFEE_STATUS: %s\n", configObj.getState("COFFEE_STATUS").c_str());
    printf("COFFEE_HEALTH_URL: %s\n", configObj.getState("COFFEE_HEALTH_URL").c_str());

    return EXIT_SUCCESS;
}
