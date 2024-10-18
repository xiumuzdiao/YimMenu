# Editor's note 

Author: https://github.com/YimMenu or https://gitlab.com/YimMenu

Files source: https://gitlab.com/YimMenu/YimMenu

Author's latest version file update address：https://www.unknowncheats.me/forum/grand-theft-auto-v/476972-yimmenu-1-69-b3337.html

This code base is only a backup resource. The original author's code has been deleted. This code is only for learning purposes. The security and availability of the code are not guaranteed. So far, the original author is still updating, and the update address can be found in the above link.

⚠ Recently, **Rockstar has updated GTAOL**. The latest version is **b3351**. It is unclear whether this version (b3337) is applicable.

# Author's note (from Unknowncheats by Yimura)

The YimMenu source code has been partially DMCA'd, as a precaution we have taken down the whole repository and its contents.

In the future we'll be working towards adding parts of the code base online again (mainly the Lua documentation).

For now we'll be moving to binary releases only via UnknownCheats, DLL files being shared outside of UC should never be trusted unless you know and trust the person.

# YimMenu

This release is made for GTA V 1.69 b3337

A mod menu base for Grand Theft Auto V.
Strictly for educational purposes.

YimMenu is originally based of off [BigBaseV2](https://github.com/Pocakking/BigBaseV2) which was an amazing base at the time but nowadays is a bit dated.
So here I am with an up-to-date menu focusing on protecting the user from toxic modders.

## Table of contents

 * [How to build](#how-to-build)
 * [Make your own flavour of YimMenu](#make-your-own-flavour-of-yimmenu)
 * [Staying Up To Date](#staying-up-to-date)
 * [Project Structure](#project-structure)
 * [Contributing](#contributing)
 
## How to compile YimMenu

Read the [SETUP](https://gitlab.com/YimMenu/YimMenu/wiki/Setup-your-PC-for-YimMenu-Development) guide.

## Make your own flavour of YimMenu

Fork YimMenu and git clone that repository instead of https://gitlab.com/YimMenu/YimMenu.git

Click the below link to make your own fork of YimMenu:
https://gitlab.com/YimMenu/YimMenu/fork
  
## Staying Up To Date

Pull the latest changes from this repository.

With a command line it is as easy as:

```bash
git pull
```

CMake should be handling removed / added files automatically without any user input.

If this is not the case for some reason you'll have to redo the steps in the [Making changes to the source code section of the SETUP](https://gitlab.com/YimMenu/YimMenu/wiki/Setup-your-PC-for-YimMenu-Development#making-changes-to-the-source-code).

If you are doing custom modifications to the codebase and have a fork you are on your own for staying up to date with upstream (this repository), google stuff like "merge from upstream" and learn how to use Git.

## Project Structure

- `backend/` all features that should be ran in a loop are in here sorted by category
- `gui/` includes everything related to UI elements
- `hooks/` function hooks
- `native_hooks/` hooks to natives
- `services/` service files to interact and maintain stuff
- `util/` general utility functions to keep code as compact and as much in one place as possible

## Contributing

You're free to contribute to YimMenu as long as the features are useful, not overly toxic and do not contain anything money related that might get the menu targeted by Take2.

Make sure to read the [CONTRIBUTING.md](CONTRIBUTING.md) file.
