#ifndef PACKAGE_MANAGER_H
#define PACKAGE_MANAGER_H

#include <bits/stdint-uintn.h>
#include <exception>
#include <iostream>
#include <string>
#include <list>
#include <fstream>

#define printf(fmt, ...) cout << "printf() is not supported by this Framework. Please use cout."

#include <nlohmann/json.hpp>

struct Package
{
	std::string name;
	uint32_t versionMajor;
	uint32_t versionMinor;
	uint32_t size;
};

class PackageManager
{

public:
PackageManager()
{
	coPackageSize = 0; 
}	

	void add(Package package)
	{
		
		for (auto &  ele: storedPa)
		{
			if ((ele.name == package.name)
				&& (ele.versionMajor == package.versionMajor) 
				&& (ele.versionMinor == package.versionMinor))
			{
			return;
			 
			}
		}
		if (storedPa.size() > 9){
			throw std::invalid_argument( "to many pakages >10" );
		}
		if (package.size == 0){
			throw std::invalid_argument( "Package size  0" );
		}
		if ((coPackageSize+package.size) > 100){
			throw std::invalid_argument( "to big package  >100 bytes" );
		}
			
		storedPa.push_back(package);
			
		coPackageSize =  coPackageSize + package.size;//add a size package
			
	
		
	}

	void remove(const std::string& name, uint32_t versionMajor, uint32_t versionMinor)
	{
				
		for (std::list<Package>::iterator ite=storedPa.begin(); 
			ite!=storedPa.end(); ++ite)
		{
			if ( (ite->name == name)
		      && (ite->versionMajor == versionMajor) 
		      && (ite->versionMinor == versionMinor))
			{
			
				coPackageSize = coPackageSize - (ite->size); 
				storedPa.erase(ite);
			    return;
				
			}
	
		}
	  	throw std::invalid_argument( "didn't find an element to remove" );

		
	}

	Package retrieve(const std::string& name, uint32_t versionMajor, uint32_t versionMinor)
	{
		
		for (auto &ele : storedPa)
		{
	   		if ( (ele.name == name)
		      && (ele.versionMajor == versionMajor) 
		      && (ele.versionMinor == versionMinor))
		   	{
				std::cout << "read "<<name<<std::endl;
				return ele;
		   	}
		   	
		}
			
		throw std::invalid_argument( "retrive not found" );

	}

	void savePackageJSON(const std::string& name, uint32_t versionMajor, uint32_t versionMinor)
	{
		std::string fileName = "";
		nlohmann::json job;
		Package mypackage = retrieve(name,versionMajor,versionMinor);
		
		job["name"] = name;
		job["size"] =  mypackage.size;
		job["versionMajor"] = versionMajor;
		job["versionMinor"] = versionMinor;
		std::ofstream schreiben;
		fileName = name + ".json";
        schreiben.open(fileName);   
        schreiben << job; 
		schreiben.close(); 
	}

private:

	std::list< Package> storedPa; // store list for packages
	uint32_t coPackageSize; //store  size of all packages
	
};

#endif
