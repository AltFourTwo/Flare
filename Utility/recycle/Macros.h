#pragma once

// This macro is used whenever a constructor has no logic and only initialize its members.
// The braces are required even when empty, but Visual Studio places them on a new line and
// there is no option to have them on the same line when empty. 
// Should appear with a ; right after to prevent further indentation issues.
#define EMPTY_SCOPE {}