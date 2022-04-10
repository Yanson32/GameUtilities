#include "GameUtilities/Core/PreferencesManager.h"
#include "GameUtilities/Core/Paths.h"
#include "GameUtilities/Core/Thread.h"
#include <iostream>
#include <filesystem>
#include <sstream>

int main()
{

  //Create a config directory
  GU::Core::String path = GU::Core::getConfigDir("Test");
  if(!std::filesystem::exists(path.toStdString()))
    std::filesystem::create_directory(path.toStdString());

  path += "/config.txt";

  //Create preferences manager
  GU::Core::PreferencesManager manager(path);

  //Add some values to the preferences file
  manager.write("GameUtilities", 55.8f);
  manager.write("Skittles", "Taste the rainbow");
  manager.write("Test", 12);

  //Read a previously written value
  int defaultValue = 5;
  int value = manager.read("Test", defaultValue);
  std::stringstream outputMsg;
  outputMsg << "The value of Test is ";
  outputMsg << value;
  GU::Core::ts_iostream(std::cout, outputMsg.str());

  //Replace the first entry with a new value
  manager.write("GameUtilities", 14.40f);

}
