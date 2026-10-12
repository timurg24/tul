# Timur's Utility Library (tul)

A set of helper functions that eliminate the need to rewrite some common functions you might find in most programs.

## ErrorOps

Check the `ErrorOps.hpp` file for color and escape code defines.

- `Print` - Prints out a message
- `Alert` - Displays a message box (on non-Windows systems it displays the console wit the error message)
- `FatalError` - Displays a message box and closes the application (console on non-Windows)

## FileOps

- `ReadFile` - Reads a file into a string

## StringOps

- `SplitString` - Splits a string with a delimeter into a vector of strings
- `HashString` - Hashes a string into `uint32_t`
- `SetLocalizationData` - Loads a JSON file containing locale strings (see `examples/locale.json`)
- `SetLocale` - Sets a locale (example en-US, ru-RU)
- `GetLocaleString` - Gets a value based on a key

## CliOps

Provides an easy interface to get command line arguments.

- `SetupArguments` - Sets up the arguments to be used by other functions
- `CheckArgument` - Checks if argument exists, then returns index if it does
- `GetArgument` - Returns the string argument at index
- `GetValue` - Keys a value based on a key
  - Example: `--language=english`, key "language" will return value "english"
  - Example: `--preset=launch.txt`, loads a text file with each new line being added as an argument