# Whats  PE Injection?
- **PE injection** Is A Method Of Executing Arbitrary Code In The Address Space Of A Separate Live Process.
## Technical Details(Advanced)
1) First We Should Get Image Base Address From The PE Header
2) We Should Get The Size From The PE Header
3) We Should Allocate A Block Of Memory
4) We Should Copy The Image Of The Current Process Into The New Block Of Memory
5) We Should Allocate Another Block Of Memory In A Remote Process
6) We Should Calculate The Offset Of The Reloc Table
7) We Should Relocate The PE
8) We Should CreateRemoteThread And Point It To The Function
## How PE Injection Works?
![PEinjection](https://user-images.githubusercontent.com/107004485/184161972-3116df4b-2a48-4cc4-ae4c-c63c73599531.gif)
## Result Of Injection Of Notepad Process Using PE Injection
![image](https://user-images.githubusercontent.com/107004485/184226015-2489b041-568e-4f37-bff7-4a873e769a49.png)

## Big Thanks To [Uncle Jack](https://github.com/UncleJ4ck), He Helped Me A Lot In Code Management And Some Stuff
