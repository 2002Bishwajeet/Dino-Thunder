# Dinasaur-Game-CPP

This is an attempt to make a chrome dinosaur game using CPP and an any Graphics Library

## Installation

Most of the header files are present in the src folder. However you need to add those path in your workspace folder. Usually the extension will give you a suggesstion to add in the path. 

If it doesn't happen add the following lines in your `c_cpp_properties.json` file.

```json
{
"configurations": [
    {
        "includePath": [
            "${workspaceFolder}/**",
            "${workspaceFolder}/src/include"
        ],
      
    }
],
}
```
