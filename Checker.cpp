#include <assert.h>
#include <iostream>
using namespace std;

// Pure function: checks if value is within range
bool isValueOk(float value, float min, float max) {
  return value >= min && value <= max;
}

// Helper function: prints reason for breach and whether high or low
void printBreachReason(const char* name, float value, float min, float max) {
  // Only one decision point: use if-else chain
  if (value < min)
    cout << name << " is too low!\n";
  else if (value > max)
    cout << name << " is too high!\n";
}

// Function: checks battery and prints all breach reasons
// Only one loop, no nested decisions
bool checkBatteryAndPrint(float temperature, float soc, float chargeRate) {
  const char* names[3] = {"Temperature", "State of Charge", "Charge Rate"};
  float values[3] = {temperature, soc, chargeRate};
  float mins[3] = {0, 20, 0};
  float maxs[3] = {45, 80, 0.8};
  bool allOk = true;
  for (int i = 0; i < 3; ++i) {
    if (!isValueOk(values[i], mins[i], maxs[i])) {
      printBreachReason(names[i], values[i], mins[i], maxs[i]);
      allOk = false;
    }
  }
  return allOk;
}

int main() {
  // Only one assertion per test, no branching
  assert(checkBatteryAndPrint(25, 70, 0.7) == true);
  assert(checkBatteryAndPrint(50, 85, 0) == false);
  assert(checkBatteryAndPrint(-1, 10, 0.9) == false);

  return 0;
}
