# Tasks
---
## Where did I Stop
- I finished the searchbar - ProxyLibrary.
- Time to Start the TextPlaylist Item.

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

## Pending OnClickedMethods: LibraryA - SearchBar
1. Library: Add function to onClicked() delegates
2. Search Bar: Make the functions of:
    - Search button
    - Plus button
    - Filter button

## Pending Problems: SearchBar - Library A
1. Search Bar: SearchLibrary
    -Problem: SearchBar->SearchLibrary visible: is not fully connected to the focus property of textIntro.
    -Possible Solution: attach visible to textOnChanged of textIntro.
2. LibraryA: Bar
    -Problem: the bar isn't working when u click on it
    -Posible Solution: focus?-drag?
    -Real problem: a MouseArea was coverting the entire LibraryA, that's why was not receiving Clicks events.
    -Solution: That mousearea was created for changing the focus of GridView. So i deletd it salaberga siuu
## Second Level: LibraryA
2. Completed - **Learn** how to use a bar with the library. (Scroll View) - (Slider). 
3. Completed - I need to add a mask to an Image in Delegate, for a border image.
4. Completed - Move the code of the RoundedImage to a separate file .qml.
5. Completed - Add a OnMouseHover and OnSelected effect over the RoundedImage.
6. Completed - Start the blueprint of Search Bar.
7. Obsidian: Documentate everything so far.

## Third Level: SearchBar 
1. Completed - Make the delegates of Search Bar.
2. Completed - C++: I need to implement a void search function in libraryBackend, using algorithms and magic stuff.
3. Completed - Learn about **QSortFilterProxy** model and implement it.

## Fourth Level: MusicAnnotator
- Start making a .qml sample of an textAnnotator.
