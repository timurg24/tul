# Timur's Utility Library (tuls)

A set of helper functions that eliminate the need to rewrite some common functions you might find in most programs.

## Error

- `Print` - Prints out a message
- `Alert` - Prints out a red alert message
- `FatalError` - On Windows, displays an error message box and closes the application

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
