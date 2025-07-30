---
title: Operating Systems
author: S. Shahriar <shadowshahriar@gmail.com>
subject: Lab Report 1
keywords: os, wsl, ubuntu
colorTheme: light
codeTheme: stackoverflow-light
fonts: ['Nunito:ital,wght@0,200..1000;1,200..1000', 'JetBrains+Mono:ital,wght@0,100..800;1,100..800']
cssFontText: ['Nunito']
cssFontCode: ['JetBrains Mono']
cssFontEmoji: ['Noto+Color+Emoji']
cssWatermark: ['20245103408']
specialWords: ['Ans.', 'Output:']
cssPageHeader: ['']
headerClass: new-page
lang: none
addCover: true
coverPageName: Cover Page
cssPageNumberPlacement: right
preset: none
---

::: {#cover.border}

<section>
	<img id="watermark" class="round" src="./bubt.png" width="200px" />
</section>
<section>
	<p class="h1 w800 underline text-upr">Lab Report</p>
	<table class="compact borderless table-large table-upr padless" style="width: 5.1in">
		<tr>
			<th>Course Title</th>
			<th>:</th><td>Operating Systems Lab</td>
		</tr>
		<tr>
			<th>Course Code</th>
			<th>:</th><td>CSE 210</td>
		</tr>
		<tr>
			<th>Lab Report No.</th>
			<th>:</th><td>01</td>
		</tr>
		<tr>
			<th>Submission Date</th>
			<th>:</th><td>29-07-2025</td>
		</tr>
	</table>
</section>
<section style="--hw: 7.2rem;">
	<p class="h2 w800 text-upr">Submitted To</p>
	<table class="compact borderless table-large table-upr padless withleader">
		<tr>
			<th>Name</th>
			<td>Mishal Al Rahman</td>
		</tr>
		<tr>
			<th>Dept. of</th>
			<td>Computer Science and Engineering (CSE)</td>
		</tr>
		<tr>
			<th></th>
			<td>Bangladesh University of Business & Technology (BUBT)</td>
		</tr>
	</table>
</section>
<section style="--hw: 7.2rem;">
	<p class="h2 w800 text-upr">Submitted By</p>
	<table class="compact borderless table-large table-upr padless withleader">
		<tr>
			<th>Name</th>
			<td>Shadman Shahriar</td>
		</tr>
		<tr>
			<th>ID No.</th>
			<td>20245103408</td>
		</tr>
		<tr>
			<th>Intake</th>
			<td>53</td>
		</tr>
		<tr>
			<th>Section</th>
			<td>1</td>
		</tr>
		<tr>
			<th>Program</th>
			<td>B.Sc. Engg. in CSE</td>
		</tr>
	</table>
</section>

:::

::: {.centered-heading}

# Operating Systems Lab

:::

### 1. Display the path of your current directory

```bash
pwd
```

![Retrieving the present working directory using the pwd command.](images/00.png)

### 2. Create a new directory called `LabFiles` in your home directory

```bash
mkdir LabFiles
```

### 3. Navigate into `LabFiles` directory

```bash
cd LabFiles
```

### 4. Create three new directories inside `LabFiles`

-   📁 FileDir1
-   📁 FileDir2
-   📁 FileDir3

```bash
mkdir FileDir1 FileDir2 FileDir3
```

![Creating directories using the mkdir command.](images/01.png)

### 5. Create three new files inside the new directories

-   📄 **file1.txt** inside 📁 **FileDir1**
-   📄 **file2.txt** inside 📁 **FileDir2**
-   📄 **file3.txt** inside 📁 **FileDir3**

```bash
touch FileDir1/file1.txt
touch FileDir2/file2.txt
touch FileDir3/file3.txt
```

### 6. List the files in the `LabFiles` directory

```bash
ls
```

![Listing the items in the LabFiles directory.](images/03.png)

### 7. Add some contents in the `file1.txt` and `file2.txt` file using the terminal

```bash
nano FileDir1/file1.txt
nano FileDir2/file2.txt
```

![Using nano to edit the text files directly from the terminal.](images/04.png)

![Editing file1.txt](images/05.png)

![Editing file2.txt](images/06.png)

### 8. Display the contents of `file1.txt`

```bash
cat FileDir1/file1.txt
```

![Retrieving the contents of file1.txt](images/07.png)

### 9. Make a copy of `file1.txt` called `backup.txt` in `LabFiles` directory

```bash
cp FileDir1/file1.txt backup.txt
```

![Copying file1.txt as backup.txt in the LabFiles directory.](images/08.png)

### 10. Rename `file2.txt` to `newfile.txt`

```bash
mv file2.txt newfile.txt
```

![Renaming file2.txt to newfile.txt](images/09.png)

### 11. Move `newfile.txt` to the `FileDir3` changing its name to `newfile2.txt`

```bash
mv newfile.txt ../FileDir3/newfile2.txt
```

### 12. Remove `file1.txt` from the `FileDir1` directory

```bash
rm file1.txt
```

![All of the commands that were used to complete tasks 1-20](images/full.png)
