# Tasks
---
I don't want to work anymore with notes. Just a Music Player.
## Where did I Stop
-VautTones Reamke - Add a volumeButton
## What's next?
- Change TextPlaylist for the song Image.

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

## Pending OnClickedMethods: LibraryA - SearchBar - TextPlaylist
1. Library: Add function to onClicked() delegates
2. Search Bar: Make the functions of:
    - Search button
    - Plus button
    - Filter button
3. TextPlaylist: functions of:
    - adding notes. (require another player for audionotes)
    - playPause methods.

## Pending Problems: SearchBar - Library A
1. Search Bar: SearchLibrary
    -Problem: SearchBar->SearchLibrary visible: is not fully connected to the focus property of textIntro.
    -Possible Solution: attach visible to textOnChanged of textIntro.
2. LibraryA: Bar
    -Problem: the bar isn't working when u click on it
    -Posible Solution: focus?-drag?
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

## Fourth Level: TextPlaylist
1. Completed - Start making a .qml sample of an textAnnotator.
2. Completed - First Desgin of dinamic notes.
3. Completed - Make the principal MusicPlayer.
4. Completed - Try loading a song.
5. Completed - Make the secondary AudionotePlayer.
6. Completed - Execute another mediaplayer for audio-notes.
7. Completed - Save audio-notes in the song folder.
8. Completed - Save text-notes in the song folder.?
12. Completed - Finished TextPlaylist part I.

## Fifth Level: Connecting Everything
1. Completed - Connect songFile to TextPlaylist.
2. Completed - Connect songName to TextPlaylist.
3. Completed - Add Notes in Texplaylist.
4. Completed - Connect songNotes to Texplaylist.
5. Completed - Learn how to load things to Qt in a internal folder(external project). I can try an app to load/save and show Images.
6. Completed - FileDialog+Folder Creation
7. Completed -  Finiishd TextPlaylist

## Sixth Level: AutoUpload source and Add things
1. Completed - LibraryA songs: autosearch for songs in that folder, if exists add to the app.
2. Completed - Delete audioNotes and Songs.
3. Completed - Audio-notes inside songfolders. ( save and autosearch )
4. Text-notes as i dont know how to save that.
5. Save text-notes in the notes folder. (Librarybackend::addsongNotes(QString NoteText, QString Type)).11/12/24 last thing
## Remake of VaultTones
I just wanna finish this project.
1. Completed - Add a volumeButton
2. Change de TextPlaylist for the Image of the song.
