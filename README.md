# Whats  PE Injection?
- **PE injection** is a method of executing arbitrary code in the address space of a separate live process.
## Technical Details(Advanced)
- 1) First We Should Get Image Base Address From The PE Header
- 2) We Should Get The Size From The PE Header
- 3) Allocate A Block Of Memory
- 4) Copy The Image Of The Current Process Into The New Block Of Memory
- 5) Allocate Another Block Of Memory In A Remote Process
- 6) Calculating The Offset Of The Reloc Table
- 7) Relocating The PE
- 8) CreateRemoteThread And Point It To The Function
## How PE Injection Works?
![PEinjection](https://user-images.githubusercontent.com/107004485/184161972-3116df4b-2a48-4cc4-ae4c-c63c73599531.gif)
### Big Thanks To Uncle Jack, He Helped Me A Lot In Code Management And Some Stuff
