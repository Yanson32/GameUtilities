#include "GameUtilities/Core/PreferencesManager.h"
#include <fstream>
#include <thread>
#include <cassert>
#include <string>
#include <iostream>

class PreferencesManager::Impl
{
    public:
        Impl(const GU::Core::String &path);
	#ifdef MULTITHREAD
	std::Mutex pathLock;
        #endif	
	GU::Core::String m_path;
	std::fstream m_file;
};

PreferencesManager::Impl::Impl(const GU::Core::String &path):
m_path(path)
{
    m_file.open(m_path.toStdString(), std::ios::in | std::ios::out);    
    if(!m_file)
    {
        std::cout << "The file " << m_path.toStdString() << " could not be created" << std::endl;     
    }
}


PreferencesManager::PreferencesManager(const GU::Core::String &path):
pimpl(new PreferencesManager::Impl(path))
{

}

void PreferencesManager::write(const GU::Core::String &name, const int &data)
{
    assert(pimpl != nullptr);
    pimpl->m_file << name << " : " << data << std::endl; 
}


void PreferencesManager::write(const GU::Core::String &name, const float &data)
{
    assert(pimpl != nullptr);
    pimpl->m_file << name << " : " << data << std::endl; 
}


void PreferencesManager::write(const GU::Core::String &name, const GU::Core::String &data)
{
    assert(pimpl != nullptr);
    pimpl->m_file << name << " : " << data << std::endl; 
}


int PreferencesManager::read(const GU::Core::String &name, const int &defaultValue)
{

}


float PreferencesManager::read(const GU::Core::String &name, const float &defaultValue)
{

}


GU::Core::String PreferencesManager::read(const GU::Core::String &name, const GU::Core::String &defaultValue)
{

}


PreferencesManager::~PreferencesManager()
{
    assert(pimpl != nullptr);
    pimpl->m_file.close();
    if(pimpl != nullptr)
	    delete pimpl;
}
