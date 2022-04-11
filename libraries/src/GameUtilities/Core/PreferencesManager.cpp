#include "GameUtilities/Core/PreferencesManager.h"
#include "GameUtilities/Core/Thread.h"
#include "GameUtilities/Core/RAIIStream.h"
#include <fstream>
#include <thread>
#include <cassert>
#include <string>
#include <iostream>
#include <memory>
#include <sstream>
#include <filesystem>

namespace GU
{
  namespace Core
  {
    class PreferencesManager::Impl
    {
        public:
            Impl(const GU::Core::String &path);

            template <class T>
            void copy(const GU::Core::String &name, const T &data);

            template <class T>
            T read(const GU::Core::String &name, const T &defaultValue);

            GU::Core::String read(const GU::Core::String &name, const GU::Core::String &defaultValue);
            //#ifdef MULTITHREAD
          	static std::mutex m_fileLock;
            static std::mutex m_tempLock;
            //#endif
          	GU::Core::String m_path;
            GU::Core::String m_tempPath = "";
    };
    std::mutex PreferencesManager::Impl::m_fileLock;
    std::mutex PreferencesManager::Impl::m_tempLock;

    template <class T>
    void PreferencesManager::Impl::copy(const GU::Core::String &name, const T &data)
    {
        //Create temperary file
        //Create filestream to read file
        std::ifstream fileStream;
        GU::Core::RAIIStream<std::ifstream> s(fileStream, m_path, m_fileLock);


        //Create temp file
        std::ofstream temp;
        GU::Core::RAIIStream<std::ofstream> t(temp, m_tempPath, m_tempLock);

        bool done = false;

        //Get each line from fileStream
        std::string line;
        while(std::getline(fileStream, line))
        {
          std::stringstream ss(line);
          std::string id;
          getline(ss, id, ':');
          if(id == name.toStdString())
          {
            temp << name << ":" << data << std::endl;
            done = true;
          }
          else
          {
            temp << line << std::endl;
          }
        }

        if(!done)
          temp << name << ":" << data << std::endl;
    }


    template <class T>
    T PreferencesManager::Impl::read(const GU::Core::String &name, const T &defaultValue)
    {
      std::ifstream fileStream;
      GU::Core::RAIIStream<std::ifstream> s(fileStream, m_path, m_fileLock);
      std::string line;
      while(std::getline(fileStream, line))
      {
        std::stringstream ss(line);
        std::string id;
        getline(ss, id, ':');
        if(id == name.toStdString())
        {
          T data;
          ss >> data;
          return data;
        }
      }
      return defaultValue;
    }


    GU::Core::String PreferencesManager::Impl::read(const GU::Core::String &name, const GU::Core::String &defaultValue)
    {
      std::ifstream fileStream;
      GU::Core::RAIIStream<std::ifstream> s(fileStream, m_path, m_fileLock);
      std::string line;
      while(std::getline(fileStream, line))
      {
        std::stringstream ss(line);
        std::string id;
        getline(ss, id, ':');
        if(id == name.toStdString())
        {
          std::string data;
          ss >> data;
          return data;
        }
      }
      return defaultValue;
    }


    PreferencesManager::Impl::Impl(const GU::Core::String &path):
    m_path(path)
    {
      m_tempPath = std::filesystem::temp_directory_path().string();
      m_tempPath += "/temp.txt";
    }


    /*********************************************************************************//**
    *	@brief: Constructor
    * @param: path is the full path to the preferences file
    *************************************************************************************/
    PreferencesManager::PreferencesManager(const GU::Core::String &path):
    pimpl(new PreferencesManager::Impl(path))
    {

    }


    /*********************************************************************************//**
    *	@brief: This function writes an int value to the preferences file.
    * @param: name is a unique identifyer for the data.
    * @param: data is the data to be written to the preferences file.
    *************************************************************************************/
    void PreferencesManager::write(const GU::Core::String &name, const int &data)
    {
        //Make sure the pimpl pointer is valid
        assert(pimpl != nullptr);

        //Copy data to temp file
        pimpl->copy(name, data);

        //Copy temp file to preferences file
        std::filesystem::remove(pimpl->m_path.toStdString());
        std::filesystem::copy_file(pimpl->m_tempPath.toStdString(), pimpl->m_path.toStdString());
        std::filesystem::remove(pimpl->m_tempPath.toStdString());
    }


    /*********************************************************************************//**
    *	@brief: This function writes a float value to the preferences file.
    * @param: name is a unique identifyer for the data.
    * @param: data is the data to be written to the preferences file.
    *************************************************************************************/
    void PreferencesManager::write(const GU::Core::String &name, const float &data)
    {
      //Make sure the pimpl pointer is valid
      assert(pimpl != nullptr);

      //Copy data to temp file
      pimpl->copy(name, data);

      //Copy temp file to preferences file
      std::filesystem::remove(pimpl->m_path.toStdString());
      std::filesystem::copy_file(pimpl->m_tempPath.toStdString(), pimpl->m_path.toStdString());
      std::filesystem::remove(pimpl->m_tempPath.toStdString());
    }


    /*********************************************************************************//**
    *	@brief: This function writes a GU::Core::String value to the preferences file.
    * @param: name is a unique identifyer for the data.
    * @param: data is the data to be written to the preferences file.
    *************************************************************************************/
    void PreferencesManager::write(const GU::Core::String &name, const GU::Core::String &data)
    {
      //Make sure the pimpl pointer is valid
      assert(pimpl != nullptr);

      //Copy data to temp file
      pimpl->copy(name, data);

      //Copy temp file to preferences file
      std::filesystem::remove(pimpl->m_path.toStdString());
      std::filesystem::copy_file(pimpl->m_tempPath.toStdString(), pimpl->m_path.toStdString());
      std::filesystem::remove(pimpl->m_tempPath.toStdString());
    }


    /*********************************************************************************//**
    *	@brief:  This function reads an int value from the preferences file.
    * @param:  name is a unique identifyer for the data.
    * @param:  defaultValue is the value to be returned if the value could not
    *          be read from the preferences file.
    * @return: The value read from the preferences file or the default value
    *          if the value could not be read.
    *************************************************************************************/
    int PreferencesManager::read(const GU::Core::String &name, const int &defaultValue)
    {
      assert(pimpl != nullptr);
      pimpl->read(name, defaultValue);
    }


    /*********************************************************************************//**
    *	@brief:  This function reads an float value from the preferences file.
    * @param:  name is a unique identifyer for the data.
    * @param:  defaultValue is the value to be returned if the value could not
    *          be read from the preferences file.
    * @return: The value read from the preferences file or the default value
    *          if the value could not be read.
    *************************************************************************************/
    float PreferencesManager::read(const GU::Core::String &name, const float &defaultValue)
    {
      assert(pimpl != nullptr);
      return pimpl->read(name, defaultValue);
    }


    /*********************************************************************************//**
    *	@brief:  This function reads an GU::Core::String value from the preferences file.
    * @param:  name is a unique identifyer for the data.
    * @param:  defaultValue is the value to be returned if the value could not
    *          be read from the preferences file.
    * @return: The value read from the preferences file or the default value
    *          if the value could not be read.
    *************************************************************************************/
    GU::Core::String PreferencesManager::read(const GU::Core::String &name, const GU::Core::String &defaultValue)
    {
      assert(pimpl != nullptr);
      return pimpl->read(name, defaultValue);
    }


    /*********************************************************************************//**
    *	@brief: Destructor
    *************************************************************************************/
    PreferencesManager::~PreferencesManager()
    {
        assert(pimpl != nullptr);
        if(pimpl != nullptr)
    	    delete pimpl;
    }
  }
}
