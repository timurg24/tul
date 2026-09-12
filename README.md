# Timur's Utility Library (tuls)

A set of helper functions that eliminate the need to rewrite some common functions you might find in most programs.

## ErrorOps

- `Print` - Prints out a message
- `Alert` - Displays a message (Windows only)
- `FatalError` - Displays a message box and closes the application (Windows only)

## FileOps

- `ReadFile` - Reads a file into a string

## StringOps

- `SplitString` - Splits a string with a delimeter into a vector of strings
- `HashString` - Hashes a string into `uint32_t`

## CliOps

Provides an easy interface to get command line arguments

- `SetupArguments` - Sets up the arguments to be used by other functions
- `CheckArgument` - Checks if argument exists, then returns index if it does
- `GetArgument` - Returns the string argument at index
- `GetValue` - Keys a value based on a key
  - Example: `--language=english`, key "language" will return value "english"
