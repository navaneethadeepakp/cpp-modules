#include "Serializer.hpp"
#include <iostream>

int main() {
  Data data;
  data.id = 42;
  data.name = "d1_name";

  Data *original = &data;
  uintptr_t raw = Serializer::serialize(original);
  Data *restored = Serializer::deserialize(raw);

  std::cout << "Original ptr: " << original << std::endl;
  std::cout << "Serialized: " << raw << std::endl;
  std::cout << "restored ptr: " << restored << std::endl;

  std::cout << "pointers match: " << (original == restored ? "Yes" : "No")
            << std::endl;
  std::cout << "Restored id : " << restored->id
            << ", Restored name : " << restored->name << std::endl;

  uintptr_t nullraw = Serializer::serialize(NULL);
  std::cout << "Serialized: " << nullraw << std::endl;
  Data *nullrestored = Serializer::deserialize(nullraw);
  std::cout << "Null match: " << (nullrestored == NULL ? "Yes" : "No")
            << std::endl;
}