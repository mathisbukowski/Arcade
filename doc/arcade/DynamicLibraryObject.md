---
generator: doxide
---


# DynamicLibraryObject

**class DynamicLibraryObject**



## Variables

| Name | Description |
| ---- | ----------- |
| [_handle](#_handle) | Handle to the library !!! note The handle is automatically closed when the object is destroyed  |
| [_name](#_name) | Name of the library  |
| [_type](#_type) | Type of the library  |

## Functions

| Name | Description |
| ---- | ----------- |
| [DynamicLibraryObject](#DynamicLibraryObject) | Constructor :material-location-enter: `path` :    Path to the library :material-location-enter: `type` :    Type of the library  |
| [~DynamicLibraryObject](#_u007eDynamicLibraryObject) | Destructor  |
| [getFunction](#getFunction) | Get a function from the library :material-code-tags: `FuncType` :    Type of the function :material-location-enter: `symbolName` :    Name of the symbol :material-keyboard-return: **Return** :    Function pointer  |
| [getName](#getName) | Get the name of the library :material-keyboard-return: **Return** :    Name of the library  |
| [getType](#getType) | Get the type of the library :material-keyboard-return: **Return** :    Type of the library  |
| [getEntryPointType](#getEntryPointType) | Get the library type from entryPointType function :material-keyboard-return: **Return** :    Library type from entryPointType or the default type if the function doesn't exist  |
| [getEntryPointName](#getEntryPointName) | Get the library name from entryPointName function :material-keyboard-return: **Return** :    Library name from entryPointName or the default name if the function doesn't exist  |

## Variable Details

### _handle<a name="_handle"></a>

!!! variable "std::unique_ptr&lt;void, int(&#42;)(void&#42;)&gt; _handle"

    Handle to the library
        
    !!! note
     The handle is automatically closed when the object is destroyed
    

### _name<a name="_name"></a>

!!! variable "std::string _name"

    Name of the library
    

### _type<a name="_type"></a>

!!! variable "LibType _type"

    Type of the library
    

## Function Details

### DynamicLibraryObject<a name="DynamicLibraryObject"></a>
!!! function "DynamicLibraryObject(const std::string&amp; path)"

    Constructor
    
    :material-location-enter: `path`
    :    Path to the library
        
    :material-location-enter: `type`
    :    Type of the library
    

### getEntryPointName<a name="getEntryPointName"></a>
!!! function "std::string getEntryPointName()"

    Get the library name from entryPointName function
        
    :material-keyboard-return: **Return**
    :    Library name from entryPointName or the default name if the function doesn't exist
    

### getEntryPointType<a name="getEntryPointType"></a>
!!! function "LibType getEntryPointType() const"

    Get the library type from entryPointType function
        
    :material-keyboard-return: **Return**
    :    Library type from entryPointType or the default type if the function doesn't exist
    

### getFunction<a name="getFunction"></a>
!!! function "template &lt;typename FuncType&gt; FuncType getFunction(const std::string&amp; symbolName)"

    Get a function from the library
        
    :material-code-tags: `FuncType`
    :    Type of the function
        
    :material-location-enter: `symbolName`
    :    Name of the symbol
        
    :material-keyboard-return: **Return**
    :    Function pointer
    

### getName<a name="getName"></a>
!!! function "std::string getName() const"

    Get the name of the library
        
    :material-keyboard-return: **Return**
    :    Name of the library
    

### getType<a name="getType"></a>
!!! function "LibType getType() const"

    Get the type of the library
        
    :material-keyboard-return: **Return**
    :    Type of the library
    

### ~DynamicLibraryObject<a name="_u007eDynamicLibraryObject"></a>
!!! function "~DynamicLibraryObject()"

    Destructor
    

