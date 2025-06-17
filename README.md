## SearchEff 🔍📂💪
![C++17](https://img.shields.io/badge/C%2B%2B-17-blue.svg)<br>
![Build](https://img.shields.io/badge/build-passing-brightgreen)<br>
#### A smart search platform designed to organize your notes - efficiently and effortlessly!

>_Tired trying to arrange your notes at exam time, yet being unable to find the important points? Don't worry we've got you covered!_
Presenting **SearchEff** your one-stop solution for arranging, searching and revising your notes as efficiently as possible! Implemented through fuzzy search, prefix matching and file based frequency ranking.<br>
<hr>

## About📝⭐<br>
Given the large variety of topics covered and the largely careless style of student note-making, it often becomes an overwhelming experience to sift through your entire notes at exam time. **_SearchEff_** solves this problem by simply keeping your notes organized, readily available however you need them. Implemented completely using **C++ 17**, SearchEff uses one of its key features: the _Filesystems_ library, a super smart way to handle the entire notes folder all at once.

## Featured 📖✨<br>
☑️ Your one stop solution to organizing your entire notes folder, all at once!<br>
☑️ A simple menu based UI for easy interaction.<br>
☑️ Find all your To-Do's, Ideas and To-Be-Revised pointers at a single click, your command is our order. <br>
☑️ Search for a word through your entire folder and find its occurrences in your files.<br>
☑️ Even look for the word in the file, and find it highlighted ready to be captured.<br>
☑️ Prefix search enabled as well, find all the words starting with your prefix along with their detailed frequency analysis.<br>
☑️ A colorful UX for a more engaging experience.<br>

## Preview 👀<br>
![image](https://github.com/user-attachments/assets/606ddda7-f604-4899-bede-e7626efcbc7b)
<hr>

## Getting Started ⚡

### Prerequisites 📌
✅ A C++ compatible compiler<br>
✅ Any OS : Windows/ Mac/ Linux<br>
<br>

###  Build and Run 🚀
✔️ Clone the Repo<br>
✔️ Change the folder path in the main function, to your notes folder path  (--at line 290): <br>
![image](https://github.com/user-attachments/assets/588c6fd1-c1f7-4ff7-8ab9-b2854c8d14a9)<br>
✔️ Replace all '\' characters with '/' in the path (if any)<br>
✔️ Run and enjoy!<br>

###  How it works 🛠️
1️⃣ Add all your notes as .txt files in a single folder.<br>
2️⃣ Run SearchEff and select options from the menu as desired.<br>
3️⃣ Sit back and revise stress-free!<br>

### File Structure 📔
💠 Create _.txt_ files for parsing. <br>
💠 For To-DO list points, begin line with *@to-do*.<br>
💠 For Ideas, begin line with *::idea*. <br>
💠 For To-Be_Revised points, begin line with *@to-revise*. <br>
💠 Note that these can be added anywhere in the file, though for efficient parsing, these must begin with a new line.<br>
💠 Prepare the rest of your notes as you please!<br>
💠 Run and enjoy!<br>

## Project Structure 📁

| File              | Purpose                                       |
| ----------------- | ----------------------------------------------|
| `main.cpp`        | Core logic and menu system                    |
| `pqrs`            | A sample folder having txt files for testing  |
| `README.md`       | Project Documentation                         |
<hr>

> _Happy Searching!_ 🔍 ✨
