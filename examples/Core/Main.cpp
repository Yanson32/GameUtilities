#include "GameUtilities/Core/PreferencesManager.h"
#include "GameUtilities/Core/Paths.h"
#include "GameUtilities/Core/Thread.h"
#include <iostream>
#include <filesystem>
#include <sstream>

int main()
{
  GU::Core::String path = GU::Core::getConfigDir("Test");
  if(!std::filesystem::exists(path.toStdString()))
    std::filesystem::create_directory(path.toStdString());

  path += "/config.txt";
  std::cout << "File = " << path << std::endl;
  GU::Core::PreferencesManager manager(path);

  int test = 12;
  std::stringstream inputMsg;
  inputMsg << "The input test value is ";
  inputMsg << test;
  GU::Core::ts_iostream(std::cout, inputMsg.str());
  manager.write("Test", test);

  int defaultValue = 5;
  std::stringstream outputMsg;
  outputMsg << "The test value is ";
  outputMsg << defaultValue;
  int value = manager.read("Test", defaultValue);
  std::cout << "The test value is " << value << std::endl;

}
