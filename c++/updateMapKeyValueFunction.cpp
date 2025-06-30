    #include <map>
    #include <string>
    #include <iostream>

    class Base {
    private:
        std::map<std::string, int> myMap;

    protected: // Or public, depending on desired access level
        void setMapValue(const std::string& key, int value) {
            myMap[key] = value;
        }

    public:
        Base() {
            myMap["key1"] = 10;
            myMap["key2"] = 20;
        }

        void printMap() const {
            for (const auto& pair : myMap) {
                std::cout << pair.first << ": " << pair.second << std::endl;
            }
        }
    };

    class Derived : public Base {
    public:
        void updateMapFromDerived(const std::string& key, int value) {
            setMapValue(key, value); // Call base class setter
        }
    };

    int main() {
        Derived d;
        std::cout << "Original map:" << std::endl;
        d.printMap();

        d.updateMapFromDerived("key2", 25);
        d.updateMapFromDerived("newKey", 30);

        std::cout << "\nUpdated map:" << std::endl;
        d.printMap();

        return 0;
    }