# Introduction to Source Control

## Introduction

### What is source control?

Source control tools are used to manage code.
They allow for multiple users to make changes to code files
and easily merge code together through tools like Git, Mercurial, and TFS.

#### Recommended Source Control solutions

* [**Git**](https://git-scm.com/)
* [**Mercurial**](https://www.mercurial-scm.org/)

### What is a source hosting?

There are many websites that will host your source code for free,
or for a fee.

#### Recommended Source Hosting websites


* [**GitHub**](https://github.com/) - Only uses Git
* [**BitBucket**](https://bitbucket.org/) - Can be used with Git or Mercurial

---

## Getting started with GitHub

Normally, you would download software to use Git or Mercurial through.
However, since there is some amount of a learning curve with learning to use
the source control software, we are going to take advantage of GitHub's
web interface.

Through the web interface on GitHub.com, we can...:

* **Upload files**
* **Make edits to files that are already uploaded**
* Keep a list of issues (tasks) to get done
* Maintain a little wiki page for a project
* Set up a github-hosted webpage for a project

For our projects we will just be using these top two items, but you are
free to explore!

### 1. Register on GitHub

First, register an account on GitHub. Go to [https://github.com/](https://github.com/)
and click on the "Sign up" button.

* Choose any username - you can always change it later. It might be easiest to use
your school ID for now.
* Email address - use your personal email or school email address.
* Password - specify a password.

Next, there will be a "Choose a plan" section. Just select the **free** plan.

After you're done registering, you can go to **github.com/YOUR_USER_NAME**
to create new repositories and view existing repositories.

For example, my home repository is [https://github.com/racheljmorris](https://github.com/racheljmorris).


### 2. Create a repository

For in-class lab 4, you will be working with a partner to build a program.
You can either both work at one computer (known as pair programmming),
or each tackle a different section of the program and use one repository
to store your changes and sync.

Either way, only **one** of you will create the project repository:

1. From your profile page, go to the **Repositories** tab.
![Screenshot](images/e1-00.png)

2. Click on the **New** button.
![Screenshot](images/e1-01.png)

	1. Set up a repository name, such as **CS200 CL4**
	
	2. Description is optional
	
	3. Set as **public** (anyone can see it)
	
	4. **CHECK** the **Initialize this repository with a README** box.
	
	5. Click **Create repository**.
	
Afterward you will be taken to the repository project page, which is mostly empty.


### 3. Add your teammate to the repository

Nobody can make changes to your repository unless you give them permission to do so.

Set up the repository so you and your teammate can work together:

1. Go to **Settings**
![Screenshot](images/e1-02.png)

2. Go to the **Collaborators** section. (You might have to enter your password)

3. In the **Search by username, full name or email address** box, put in your teammate's GitHub username.

4. Click **Add collaborator**

Now you can get started on the first part of the program, then come
back to this document when you're ready to upload some of your code.


### 4. (Later) Upload your code

Once you're ready to upload your code, go back to the main page of the
project repository (github.com/YOURNAME/PROJECTNAME). You can get to it
from your GitHub profile page as well.

1. Click on the **Upload files** button.
![Screenshot](images/e1-03.png)

2. Locate your source file (.cpp) and click/drag it to the "Drag files here" box.

3. Below the uploader, there's a **Commit changes** section.

	1. You should generally add a message that describes what you changed.
	Do this in the first, thin textbox.
	
4. Click on **Commit changes**.

Your file should now appear in the web interface. You can click on its name
in the repository website and it will open to view.

If you're pair programming, it is time to switch and let the other person
pull down the code and make changes!


For your group project, you might also want to **zip** your entire 
Visual Studio project file and upload that as well, so the other
person doesn't have to spend time setting up Visual Studio!


### 5. Make changes to an existing source file

When you open a source file on the GitHub web interface, there will be an
edit button that you can use to update the code.

![Screenshot](images/e1-04.png)

Click on this edit button, and a text editor will appear.

You can paste in your changes, add a commit message (in that textbox under **Commit changes**)
then click on **Commit changes** to save your changes.


### 6. Look at changes over time

You can view commits made for each file, or the entire repository.

From the repository homepage, click on the **commits* tab...

![Screenshot](images/e1-05.png)

You will be able to see everybody who has contributed to the project and their
commit messages:

![Screenshot](images/e1-06.png)

If you click on a specific commit, it will show you a summary of
what was added/removed from the source file by this commit.

![Screenshot](images/e1-07.png)

This can be helpful, even if you're working alone, so you can
keep track of what you've changed over time!
