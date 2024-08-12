# Tasks
---
## Where did I Stop
- I was customizing the ScrollBar in LibraryA, then I wanted to connect the data of
librarybackend to delegateAlbun.
## First Level: Working on Backend 
1. Finish Library Backend .cpp
2. Think about if it's better to integrate the song Local o Remote.
- Local (qrc o copying the song inside another folder)
- Remote (just the url)
- I don't know if i need to put this in the destructor of LibraryBackend:
```C++
void clearDataList() {
    qDeleteAll(m_dataList);
    m_dataList.clear();
}
```
## Second Level
2.Completed - Learn how to use a bar with the library.
(Scroll View) - (Slider) 
3.Completed - I need to add a mask to an Image in Delegate, for a border image.
