# Tasks
---
## Where did I Stop
- I was about to make the Delegates for the SearchBar, taking the info from librarybackend 
- [SearchModelVid](https://academy.qt.io/users/sign_in?next=%2Fmy-learning)
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
2. Completed - Learn how to use a bar with the library. (Scroll View) - (Slider). 
3. Completed - I need to add a mask to an Image in Delegate, for a border image.
4. Completed - Move the code of the RoundedImage to a separate file .qml.
5. Completed - Add a OnMouseHover and OnSelected effect over the RoundedImage.
6. Start the blueprint of Search Bar.
7. Obsidian: Documentate everything so far.

## Second Level: SearchBar 
1. Make the delegates of Search Bar.
2. Search Bar: Make the functions of:
    - Search button
    - Plus button
    - Filter button


## Third Level
1. Add function to onClicked() delegates
