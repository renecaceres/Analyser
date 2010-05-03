# USM Data Analysis Project

## General rules and coding conventions

You **must** follow the coding conventions for the project. Every change you
make to the code must be according to the established rules. A complete guide
about this can be found in the [`coding_conventions.md`][coding] file.

The mailing list (to be created soon) will be the official source of
information and communication between the developers and the maintainer.

Please **use** the [wiki][wiki]. It is a good place to put information that
everyone must know, and it can be checked anytime. A very good use will be
writing physics stuff useful for developers, or some programming guidelines to
do things better.

If you find some issue or bug, or something that must be discussed, or some
future development *to be done*, make sure of **open** an [issue][issues] for
it. The mailing list is also a good place to share your thoughts about
development.

## Integration-manager workflow

Because Git allows you to have multiple remote repositories, it's possible to
have a workflow where each developer has write access to their own public
repository and read access to everyone else's. This scenario often includes a
canonical repository that represents the *official* project. To contribute to
that project, you create your own public clone of the project and push your
changes to it. Then, you can send a request to the maintainer of the main
project to pull in your changes. They can add your repository as a remote,
test your changes locally, merge them into their branch, and push back to
their repository. The process works as follow:

1. The project maintainer pushes to their public repository.
2. A contributor clones that repository and makes changes.
3. The contributor pushes to their own public copy.
4. The contributor sends the maintainer an e-mail asking them to pull changes.
5. The maintainer adds the contributor's repo as a remote and merges locally.
6. The maintainer pushes merged changes to the main repository.

![Workflow](http://github.com/usm-data-analysis/Analyser/raw/master/doc/img/imw.png "Integration-Manager workflow")

One of the main advantages of this approach is that you can continue working,
and the maintainer of the main repository can pull in your changes at any
time. Contributors don't have to wait for the project to incorporate their
changes -- each party can work at their own pace.

> **This is the workflow we are going to use. The GitHub user
> [usm-data-analysis][usm-user] will be the integration-manager, and his
> [Analyser][analysis-repo] repository will be the official.**

This section is from [ProGit](http://progit.org) book. You can read more about
distributed workflows [here](http://progit.org/book/ch5-1.html).

## Installing and configuring Git

First you must create a free account in [GitHub](http://github.com "GitHub").
You also need a ssh key for connecting the Git server (you can found the
instructions [here](http://help.github.com/linux-key-setup "SSH key")). Then,
if you use Ubuntu or another Debian derivative, type in a terminal:

    $ sudo aptitude install git-core

This installs the `git` command line to manage your repositories. You must
configure your setting:

    $ git config --global user.name YOUR_USERNAME
    $ git config --global user.email YOUR_MAIL

Also you **must** set this, for dealing with line endings:

    $ git config --global core.autocrlf input

Now you can fork the [Analyser][analysis-repo] repository.


# Forking the official Analyser repository

The first thing you must do is to create your fork of the
[`Analyser`][analysis-repo] repository. To do this, you just simply click the
*fork* button on the project's page

![Fork Button](http://github.com/usm-data-analysis/Analyser/raw/master/doc/img/fork-button.jpg "Fork Button")

When the process is finished, you have a repository in your account named
`Analyser`. This is your own public repository, your fork (copy) of the
original, and this is where you will publish your changes.

## Getting your private clone of the fork

### Clone your repository

Now you need to clone your fork, to start working on it. Make sure you use the
Private URL and **not** the Public one.

    $ git clone git@github.com:YOUR_USER/Analyser.git

Or if you prefer to change the directory name:

    $ git clone git@github.com:YOUR_USER/Analyser.git DIRECTORY_NAME

### If you already have a clone of smancill's Analysis_files repository

The [`Analyser`][analysis-repo] repository of `usm-data-analysis` is a clone
of the `Analysis_files` repository of `smancill`, with new commits, so if you
cloned the old `Analysis_files` repository you can use that working copy and
do the following to synchronize it with your fork:

1. First you remove the `Analysis_files` repository from your remotes

        $ git remote rm origin

2. Now add your fork as your new `origin` remote repository

        $ git remote add origin git@github.com:YOUR_USER/Analyser.git

3. Get all the objects from your fork that you do not have yet in your local
   repo

        $ git fetch origin

4. Finally merge the `master` branch of your fork into your local `master` branch

        $ git checkout master
        $ git merge origin/master

5. You must resolve any conflicts that may appear. Now you can continue your work.


## Following the official Analyser repository

Once the clone is complete your repo will have a remote named `origin` that
points to your fork on GitHub. Don't let the name confuse you, this does **not
point** to the original [`Analyser`][analysis-repo] repo you forked from. To
help you keep track of that repo you have to add another remote named
`upstream`.

    $ cd Analyser
    $ git remote add upstream git://github.com/usm-data-analysis/Analyser.git
    $ git fetch upstream

Note that you used the public clone URL for upstream, so you can't push changes
directly to it. You don't have permission to do that, which is why you're
creating a fork in the first place.

## Pushing your changes

Now that you've got the fork, you need to make a few changes and commit them
locally. Once you've done this, it's time to push your updated branch.

    $ git push origin master

After you've pushed your commit(s) you need to inform the integration manager
of the changes so he can pull them into the blessed repo. From your project's
page, click the *pull request* button.

![Pull-request](http://github.com/usm-data-analysis/Analyser/raw/master/doc/img/pull-request.png)

Fill in a note and pick who to send the request to (it should be the user
`usm-data-analysis`).

## Pulling in upstream changes

Some time has passed, the upstream repo has changed and you want to update your
fork before you submit a new patch. There are two ways to do this:

    $ git fetch upstream
    $ git merge upstream/master

    $ git pull upstream master

`git pull` is a more direct way, but the merge it performs can be confusing if
the user doesn't expect it and a merge conflict results. `git fetch` will also
grab all branches, where `git pull` will only grab the one specified.

If you have local commits that are not in the upstream branch, a normal merge
will occur. If your local commits are in the upstream branch, a fast-forward
merge will be done, moving your local branch to the same commit as
`upstream/master`. If both repos have edits to the same location in the same
file, you may run into a merge conflict. Conflicts must be resolved by hand
and a commit made to complete the merge.

Now that your local branch has been updated, you can commit, push, and send a
pull request.

You should always do the fetch and merge manually, instead of letting `git
pull` do it for you. This can sometimes help avoid headaches caused by
mysterious merge conflicts.


# Basic Git

Git is a distributed revision control system with an emphasis on being fast.
Git was initially designed and developed by Linus Torvalds for Linux kernel
development.

Every Git working directory is a full-fledged repository with complete history
and full revision tracking capabilities, not dependent on network access or a
central server.

Git thinks of its data more like a set of snapshots of a mini filesystem.
Every time you commit, or save the state of your project in Git, it basically
takes a picture of what all your files look like at that moment and stores a
reference to that snapshot.

## Concepts

* **Repository:**   A *repository* is a collection of *commits*, each of which
  is an archive of what the project's *working tree* looked like at a past
  date, whether on your machine or someone else's. It also defines `HEAD`,
  which identifies the branch or commit the current working tree stemmed from.
  Lastly, it contains a set of *branches* and *tags*, to identify certain
  commits by name.

* **The Index:** Unlike other, similar tools you may have used, Git does not
  commit changes directly from the *working tree* into the *repository*.
  Instead, changes are first registered in something called *the index*.
  Think of it as a way of confirming your changes, one by one, before doing a
  commit (which records all your approved changes at once). Some find it
  helpful to call it instead as the *staging area*, instead of the index.

* **Working Tree:** A *working* tree is any directory on your filesystem
  which has a *repository* associated with it (typically indicated by the
  presence of a sub-directory within it named `.git`). It includes all the
  files and sub-directories in that directory.

* **Commit:** A *commit* is a snapshot of your working tree at some point in
  time. The state of `HEAD` at the time your commit is made becomes that
  commit's parent. This is what creates the notion of a revision history.

* **Branch:** A *branch* is just a name for a *commit* (and much more will
  be said about commits in a moment), also called a reference. It's the
  parentage of a commit which defines its history, and thus the typical notion
  of a branch of development.

* **Tag:** A *tag* is also a name for a commit, similar to a branch, except
  that it always names the same commit, and can have its own description text.

* **master:** The mainline of development in most repositories is done on a
  branch called `master`. Although this is a typical default, it is in no way
  special.

* **HEAD:** `HEAD` is used by your repository to define what is currently
  checked out. If you checkout a branch, `HEAD` symbolically refers to that
  branch, indicating that the branch name should be updated after the next
  commit operation. If you checkout a specific commit, `HEAD` refers to that
  commit only. This is referred to as a detached `HEAD`, and occurs, for
  example, if you check out a tag name.

## Git objects model

Git has two data structures: a mutable index that caches information about the
working directory and the next revision to be committed; and an immutable,
append-only object database.

The object database contains four types of objects:

* A blob object is the content of a file. Blob objects have no names,
  timestamps, or other metadata.
* A tree object is the equivalent of a directory. It contains a list of
  filenames, each with some type bits and the name of a blob or tree object
  that is that file, symbolic link, or directory's contents. This object
  describes a snapshot of the source tree.
* A commit object links tree objects together into a history. It contains the
  name of a tree object (of the top-level source directory), a timestamp, a
  log message, and the names of zero or more parent commit objects.
* A tag object is a container that contains reference to another object and
  can hold additional meta-data related to another object. Most commonly, it
  is used to store a digital signature of a commit object corresponding to a
  particular release of the data being tracked by Git.

Conceptually, the data in your Git repository looks something like this:

![Objects](http://github.com/usm-data-analysis/Analyser/raw/master/doc/img/objects-example.png "Stored objects in git")

If you make some changes and commit again, the next commit stores a pointer to
the commit that came immediately before it. After two more commits, your
history might look something like this:

![Commits](http://github.com/usm-data-analysis/Analyser/raw/master/doc/img/commits-example.png)

A branch in Git is simply a lightweight movable pointer to one of these
commits. The default branch name in Git is `master`. As you initially make
commits, you're given a master branch that points to the last commit you made.
Every time you commit, it moves forward automatically.

![Commits](http://github.com/usm-data-analysis/Analyser/raw/master/doc/img/master.png)

## Setting up a repository

If you want to work with an existing project, clone it:

    $ git clone <url>

If you do not have an existing git project, create one:

    $ cd project/
    $ git init

Now Git must track your files, so you have to add them and commit them:

    $ git add .
    $ git commit -m "Initial revision"

Git will look for a file named `.gitignore` in the root of your repository
which contains a set of shell patterns to ignore in file paths.

Now you can start using your repository.

## Getting help

If you ever need help while using Git, there are three ways to get the manual
page help for any of the Git commands:

    $ git help <verb>
    $ git <verb> --help
    $ man git-<verb>

For example, you can get the manpage help for the config command by running

    $ git help config

## The three states

The main thing about Git is that it has three main states that your files can
reside in: committed, modified, and staged. Committed means that the data is
safely stored in your local database. Modified means that you have changed the
file but have not committed it to your database yet. Staged means that you
have marked a modified file in its current version to go into your next commit
snapshot (the file is in the index).

![File states](http://github.com/usm-data-analysis/Analyser/raw/master/doc/img/states.png)

The basic Git workflow goes something like this:

1. You modify files in your working directory.
2. You stage the files, adding snapshots of them to your staging area.
3. You do a commit, which takes the files as they are in the staging area and
   stores that snapshot permanently to your Git directory.

If a particular version of a file is in the git directory, it's considered
committed. If it's modified but has been added to the staging area, it is
staged. And if it was changed since it was checked out but has not been
staged, it is modified.

## Simple daily workflow

When dealing with git, it's best to work in small bits. Rule of thumb: if you
can't summarise it in a sentence, you've gone too long without committing. A
typical work cycle would be:

1. Work on your project. Edit files.

2. Check which files you've changed. You can see which of your files are
   untracked, which ones are modified, and which will be committed:

        $ git status

3. Check what the actual changes were (it compares your working tree with your
   index):

        $ git diff

4. This version of `diff` checks if there are whitespace errors. You **must**
   do this before committing.

        $ git diff --check

5. If you want to discard changes in your working directory (unmodify a
   modified file):

        $ git checkout -- file2

6. Add any files/folders mentioned in step 2 (or new ones) to the index. This
   is used to begin tracking new files, and for staging modified files that
   were already tracked.

        $ git add file1 newfile2 newfolder3

7. If you want to move or remove files:

        $ git mv file_from file_to

        $ git rm file

8. You can also remove a file from git, but still keep it in your working
   directory (now the file is not tracked by git):

        $ git rm --cached -- file

9. Check changes that you will commit:

        $ git diff --staged

10. To unstage files (removing them from the index, so they will not be
   committed):

        $ git reset HEAD -- file1

11. Commit your work:

        $ git commit

12. Enter and save your commit message. If you want to back out, just quit the
    editor.

Repeat as much as you like. Just remember to always end with a commit.

> **Always try to make each commit a logically separate changeset.  Try to
> make your changes digestible. Use the staging area to split your work into
> at least one commit per issue, with a useful message per commit.**
>
> **The project snapshot at the tip of the branch is identical whether you do
> one commit or five, as long as all the changes are added at some point, so
> try to make things easier on your fellow developers when they have to review
> your changes.**
>
> **This approach also makes it easier to pull out or revert one of the
> changesets if you need to later.**


More detailed explanation can be found
[here](http://progit.org/book/ch2-2.html) and
[here](http://book.git-scm.com/3_normal_workflow.html).

### About commit messages

Here is a good model of a Git commit message:

    Short (50 chars or less) summary of changes

    More detailed explanatory text, if necessary.  Wrap it to about 72
    characters or so.  In some contexts, the first line is treated as the
    subject of an email and the rest of the text as the body.  The blank
    line separating the summary from the body is critical (unless you omit
    the body entirely); tools like rebase can get confused if you run the
    two together.

    Write your commit message in the present tense: "Fix bug" and not "Fixed
    bug."  This convention matches up with commit messages generated by
    commands like git merge and git revert.

    Further paragraphs come after blank lines.

    - Bullet points are okay, too

    - Typically a hyphen or asterisk is used for the bullet, preceded by a
      single space, with blank lines in between, but conventions vary here

    - Use a hanging indent

The short summary line should start with a uppercase letter.

All your commits **must** follow this conventions.  Getting in the habit of
creating quality commit messages makes using and collaborating with Git a lot
easier.

A detailed discussion can be found
[here](http://tbaggery.com/2008/04/19/a-note-about-git-commit-messages.html).

### Changing the commit message editor

If you don't like the default editor to write your commit messages, you can
change it whit

    $ git config --global core.editor "editorcommand"


## Viewing history

After you have created several commits, or if you have cloned a repository
with an existing commit history, you'll probably want to look back to see what
has happened.

To see what you (or others) have done so far, type:

    $ git log

To just see the last few commits you've made:

    $ git log -n3

    $ git log --since="3 weeks ago"

Replace 3 with whatever you feel like.

To see the commits that modify certain file or directory:

    $ git log -- Makefile

    $ git log -- analysis_lib/src/

For a complete overview, type:

    $ git log --stat --summary

    $ git log --oneline

To see your log graphically, you can use:

    $ git log --oneline --graph --left-right

A GUI tool can be used too:

    $ gitk

More advanced examples can be found [here](http://progit.org/book/ch2-3.html) and
[here](http://book.git-scm.com/3_reviewing_history_-_git_log.html).


## Viewing changes

If the `git status` command is too vague for you --you want to know exactly
what you changed, not just which files were changed-- you can use the `git
diff` command.

To view changes you haven't committed yet (it compares your index with your
working directory):

    $ git diff

To view changes that will be in your next commit (it compares your last commit
with your index):

    $ git diff --staged

To view changes since your last commit (it compares your last commit with your
working directory)

    $ git diff HEAD

To see what files were changed, and how many changes were made:

    $ git diff --stat

    analysis_lib/include/TIdentificator-inl.h |   89 ----------
    analysis_lib/include/TIdentificator.h     |    2 +-
    analysis_lib/include/TIdentificator.icc   |   89 ++++++++++
    doc/coding_conventions.md                 |  257 +++++++++++++++++++++++++++++
    test/2_events_sample/Makefile             |    2 +-
    5 files changed, 348 insertions(+), 91 deletions(-)

To limit output to changes in certain file(s):

    $ git diff -- file1
    $ git diff -- directory

If you want changes between versions of your project, first you'll need to
know the commit ID for the changes:

    $ git log --oneline

    34ec4a4 Fix target 'all' dependencies in Makefile
    4f69ebe name change for inline functions file
    071c737 Add coding conventions
    25a2aa5 Add remaining functions of Hayk's header file
    f1ce30c Convert some member functions to inline functions
    122ab0b Refactoring of Analysis library

The 7 characters at the front of each line is the commit ID. You'll also see
them when you commit. You can use it to show differences between commits.
Remember that a branch is just a pointer to one commit, and `HEAD` always
point to the first commit of the branch you are. So you can use a commit ID or
a branch name to refer a commit.

To view the changes between the 1st and 2nd commits, type:

    $ git diff 4f69..34ec

To view the last changes you made:

    git diff HEAD^..HEAD

To view the changes between `commit1` and the common ancestor of `commit1` and
`commit2`:

    $ git diff commit2...commit1

You can find more info on this
[link](http://book.git-scm.com/3_comparing_commits_-_git_diff.html).

## How to fix mistakes

Haven't committed yet, but don't want to save the changes? You can throw them
away:

    git reset --hard HEAD

You can also do it for individual files, but it's a bit different:

    git checkout HEAD -- myfile.txt

Messed up the commit message? This will let you re-enter it:

    git commit --amend

Forgot something in your last commit? That's easy to fix.

    git reset --soft HEAD^
    git add "files you forgot"
    git commit

Don't make a habit of overwriting/changing history if it's a public repo
you're working with, though.

## Identifying commits

### Absolute commit names

The most rigorous name for a commit is its hash identifier. The hash ID is an
absolute name, meaning it can only refer to exactly one commit. It doesn't
matter where the commit is among the entire repository's history; the hash ID
always identifies the same commit.

Each commit ID is globally unique—not just for one repository, but for any and
all repositories. For example, if a developer writes to you referring to a
particular commit ID in his repository and if you find the same commit in your
repository, you can be certain that you both have the same commit with the
same content.

Since a 40-hex-digit SHA1 number makes for tedious and error-prone entry, Git
allows you to shorten this number to a unique prefix

### refs and symrefs

A ref is a SHA1 hash ID that refers to an object within the Git object store.
Although a ref may refer to any Git object, it usually refers to a commit
object. A symbolic reference, or *symref*, is a name that indirectly points to
a Git object. It is still just a ref. Local topic branch names, remote
tracking branch names, and tag names are all refs.

Git maintains several special *symrefs* automatically for particular purposes.
They can be used anywhere a commit is used. As example, `HEAD` always refers
to the most recent commit on the current branch.

### Relative commit names

Git also provides mechanisms for identifying a commit relative to another
reference, commonly the tip of a branch.

Except for the first root commit, each commit is derived from at least one
earlier commit and possibly many, where direct ancestors are called parent
commits.

Given a commit `C`, `C^1` is the first parent, `C^2` is the second parent, and
so on.

           --O---O---C^1
                        \
                         \
           --O---O---C^2--C
                         /
                        /
           --O---O---C^3

The tilde is used to go back before an ancestral parent and select a preceding
generation.  Again, given the commit `C`, `C~1` is the first parent, `C~2` is
the first grandparent, and `C~3` is the first great-grandparent.

         C~3---C~2---C~1
                        \
                         \
           --O---O---C^2--C
                         /
                        /
           --O---O---C^3

The abbreviated forms `C^` and `C~` are the same as `C^1` and `C~1`,
respectively. Also, `C^^` is the same as `C^1^1`, and since that means the
*first parent of the first parent of commit* `C`, it refers to the same commit
as `C~2`.

### Commit ranges

A commit range is a shorthand for a series of commits.  It is denoted with a
double-period (`..`), as in `start..end`, where `start` and `end` may be
specified using the above forms.

A range is defined as the set of commits reachable from `end` end that are not
reachable from `start`.  The commit `end` is included while the commit `start`
is excluded.

You can exclude a specific commit, `X`, and all commits reachable from `X` with
the expression `^X`. So, `X..Y` representes the underlying form `^X Y`.

By example, the range `HEAD~5..HEAD~3` represents the commits `D` and `F`:

            A---B---C---D---E---F---G       master

The range `topic..master` represents those commits in `master` but not in
`topic`. Every commit reachable from `topic` is excluded, leaving `W`, `X`,
`Y` and `Z`.

               ---O---A---B---C---D         topic
                     /             \
                    /               \
        ---T---U---V---W---X----Y----Z      master

If you leave either the `start` or `end` commits out of range, `HEAD` is assumed.
Thus, `..end` is equivalent to `HEAD..end` and `start..` is equivalent to
`start..HEAD`.

Finally, the notation `A...B` (using three periods) represents the symmetric
difference between `A` and `B`, or the set of commits that are reachable from
either `A` or `B` but not from both.

By example, `master...dev` gives commits `D`, `E`, `F`, `G`, `H`, `I`, `X`,
`Y` and `Z`.

       A---B---C---D---E---F---G---H---I    master
                \             /
                 \           /
                  U----V----W---X---Y---Z   dev

## Branching and merging

The use of branches is where Git probably differs most from CVS to most users.
Under Git branches are used extensively, and they are essentially free. It
costs nearly nothing to create branches, both in terms of time and disk space.
Also, there is no need to tag first and branch second, like in CVS.

A branch in Git is simply a lightweight movable pointer to one of the commits.
The default branch name in Git is `master`. As you initially make commits,
you're given a `master` branch that points to the last commit you made. Every
time you commit, it moves forward automatically.

### Working on a topic branch

If you're going to make a bunch of changes related to a single feature, it
might be a good idea to make a *topic branch*: a branch related to a
topic or feature.

To make a new branch:

    $ git branch testing

To view the current branches:

    $ git branch

      testing
    * master

To switch to your new branch and to start working under it, just type:

    $ git checkout testing

If you check the branches again, you'll see the switch:

    $ git branch

    * testing
      master

A shorthand to create and checkout a new branch in one step is:

    $ git checkout -b testing

You are not limited to start a new branch in the tip of your current branch.
Any commit can be used as the starter point of a branch.

    $ git checkout -b newBranch topic       # from a different branch
    $ git checkout -b newBranch 4t5yul5     # from a commit
    $ git checkout -b newBranch HEAD~4      # from 4 commits behind your HEAD


Now go through the usual edit/commit cycle. Your changes will go onto the new
branch, and it will look like this:

![Branch example](http://github.com/usm-data-analysis/Analyser/raw/master/doc/img/branch-example.png)

Because a branch in Git is in actuality a simple file that contains the 40
character SHA-1 checksum of the commit it points to, branches are cheap to
create and destroy

When you want to put your branch changes back onto master, first switch to
master:

    $ git checkout master

Then merge the branch changes:

    $ git merge testing

This will combine the changes of the `master` and `testing` branches. If you
didn't change the `master` branch, git will just *fast-forward* the `testing`
changes so master is up to date. Otherwise, the changes from master and
`testing` will be combined.

You can see the commit in your project's log:

    $ git log -n1

If you're happy with the result, and don't need the branch any more, you can
delete it:

    $ git branch -d testing

Now when you see the branches, you'll only see the master branch:

    $ git branch

    * master

### Checking out when you have uncommitted changes

You can work on any existing or new branch and checkout another existing or
new branch anytime. But if you check out when you have uncommitted changes Git
issues an error message.

    $ git checkout develop

    error: Entry 'NewStuff' not uptodate. Cannot merge.

Your local changes on your current branch would be overwritten by the version
    from `develop`. To see the differences you can use

    $ git diff develop

And to show what the file looks like in the `develop` branch

    $ git show develop:NewStuff

You could commit your modified changes to your current branch

    $ git commit -a

But, if you do not want those changes into your current branch, what's needed
is a merge: the changes in your working directory must be merged with the
files being checked out.

    $ git checkout -m develop

You must resolve any conflicts that are present, and then you can start your
work under the `develop` branch.

### Detached HEAD branches

Normally, it's advisable to check out only the tip of a branch by naming the
branch directly. However, you can check out any commit. In such an instance,
Git creates a sort of anonymous branch for you called a detached HEAD.

Git creates a detached HEAD when you check out a commit that is not the head
of a branch, a tracking branch (when you want to explore changes recently
brought into your repository from a remote repository) or the commit
referenced by a tag.

    $ git branch
    * (no branch)
    master

If you later decide that you need to make new commits at that point and keep
them, you must first create a new branch.

### Viewing branches

You can make as many branches as you need at once. You can see all of them
graphically with:

    $ gitk --all

The `show-branch` command lists the commits that contribute to one or more
branches in roughly reverse chronological order.

    $ git show-branch

    ! [topic] Fix Problem Report 1
     * [dev] Improve the new development
      ! [master] Add new functions
    ---
     *  [dev] Improve the new development
     *  [dev^] Start some new development.
    +   [topic] Fix Problem Report 1
    +*+ [master] Add new functions


More detailed info about branches and merges can be found
[here](http://progit.org/book/ch3-0.html) or
[here](http://book.git-scm.com/3_basic_branching_and_merging.html).

## Working with remotes

To be able to collaborate on any Git project, you need to know how to manage
your remote repositories. Remote repositories are versions of your project
that are hosted on the Internet or network somewhere. You can have several of
them, each of which generally is either read-only or read/write for you.

To see which remote servers you have configured:

    $ git remote

    origin
    upstream

To get data from your remote projects, you can run:

    $ git fetch [remote-name]

The command goes out to that remote project and pulls down all the data from
that remote project that you don't have yet.

When you have your project at a point that you want to share, you have to push
it to your remote repository with: `git push [remote] [branch]`. To publish
your change in your private repository, you do

    $ git push origin master

### Remote branches

Remote branches are references to the state of branches on your remote
repositories. They're local branches that you can't move; they're moved
automatically whenever you do any network communication.

They take the form `(remote)/(branch)`. For instance, if you wanted to see what
the `master` branch on your `origin` remote looked like as of the last time you
communicated with it, you would check the `origin/master` branch.

    $ git checkout origin/master

    Note: moving to 'origin/master' which isn't a local branch
    If you want to create a new branch from this checkout, you may do so
    (now or later) by using -b with the checkout command again. Example:
      git checkout -b <new_branch_name>
    HEAD is now at 222ca2c... Create simbolic links for headers inside include

Because they are used exclusively to follow the changes from another
repository, you shouldn't merge or make commits onto a tracking branch.

A good explanation about remote branches is found
[here](http://progit.org/book/ch3-5.html).


# Developing the USM Data Analysis Project with Git

## Branching model

The [Analyser][analysis-repo] repository has the following branching model:

![Branching model](http://github.com/usm-data-analysis/Analyser/raw/master/doc/img/branching-model.png)

* Only code that is entirely stable will be in the `master` branch, possibly
  code that has been or will be released.

* Another parallel branch named `develop` will be used to do all the
  development work and to test stability. It isn't necessarily always stable,
  but whenever it gets to a stable state, it can be merged into master.

* The `develop` branch is used to merge topic branches (short-lived local
  branches that developers work from, for testing new features) when they're
  ready, to make sure they pass all the tests and don't introduce bugs.

All your work as developer will be done into your local `develop` branch. You
can use topic branches as you wish (you are encouraged to do it), and when you
finish something, merge your work back to `develop` branch. After you test
your work, and you are convinced that is good, push it to your public
repository and send a pull request to the maintainer to incorporate your
changes into the *blessed* repository.

When the code becomes stable, the maintainer will merge the `develop` branch
into the `master` branch, and you can fetch from his repository the new state.

If you want to read about a successful Git branching model, follow this
[link](http://nvie.com/git-model).

## Collaborating with GitHub

Coding with git backing you up is really cool because you can so easily work
on multiple topics at the same time efficiently.

You got a cool new idea and start working on it. You modify some files. You
are not yet done, and your changes not even compile yet. Meanwhile you read on
the mailing list that someone has got a problem with a specific test case and
cannot get it to work. You would like to help, but you don't know what to do
with your non finished code. You can stash it away:

    $ git stash topic_XY

Git saves away your changes and your working copy is clean and compiles again.
Now you fix the bug, commit the fix and publish it to your fork where others
can access it. Now you can apply your saved away changes and continue working
on it:

    git stash apply topic_XY

### Commit early and commit often

When you are doing much coding, maybe refactoring a large code base or
commenting source code you should keep in mind that other's are also modifying
the same code base and that conflicts may arise. In order to make it easier
for you and the others to resolve such conflicts on a per-commit basis try to
commit as often as possible and commit only small changes. Provide a
meaningful message for every commit so that anyone reviewing the commit later
knows from reading the message what the commit changes.

You can select the files that you want to commit, compare against the local
repository what changes you made and comment your changes in the commit
message. Of course it can also be done on the command line interface First
stage all changes you want to commit by using git add.

If you don't want to stage all changes in a file but only certain hunks, use
the interactive mode

    $ git add -i

or the patch mode

    $ git add --patch [FILES...]

Now check if everything has been added or if you missed something

    git status

Always keep in mind that errors happen all the time. If it is later necessary
to revert certain changes because they broke something else's code then
reverting a small commit is easy and not much of a problem. If the change to
be reverted is mixed up with lots of other changes the reverting of such a
commit will be a painful night mare. If you have already committed a "monster
commit" to your local repo then don't worry. With git it is no problem to
rewrite the commit history.

Here are some examples of commit messages for some unrelated changes that
should not be committed in the same commit object would be:

    * Converted all line endings to CRLF in the complete code base
    * Documented the methods of Class XY
    * Fixed TestcaseXY so that it now passes
    * Added a new Feature to the UI, description follows: ...


### Publishing your contribution

OK, so now you have a couple of commits that you would like to contribute to
the main repository? Better double check first if everything is fine because
errors are most easily fixed in yet unpublished changes!

* Check if the code is compiling. If you committed only a part of your
  changes, stash away the rest and check.

* Check the test suite if your changes might have broken some tests

* If your change is based on a relatively old state of the main repository
  then you should probably bring your repository up-to-date first to see if the
  change is not creating any merge conflicts. See Keeping your fork up-to-date.

If everything is OK, publish the commits to your public GitHub repository.

    $ git push origin master

Now that your commit is published, it doesn't mean that it has already been
merged into the main repository. You should issue a merge request to one of
the maintainers. They will pull your commits.

Please keep in mind, that there are many contributors and that the maintainer
may miss that something changed in your fork or forget to merge in your
commits. Remind them if they forgot.

### Publish early and often

The longer your change is not added to the main line, the higher is the
potential for merge conflicts to arise because others may have fixed the same
bug (not knowing that you already fixed it) or touched the same code for some
other reasons. So push early and often, but push only if you are sure the
changes compile and are working.

### Keeping your fork up-to-date

As your fork grows older, many other's contributions will have been merged
into the main repository and your fork will slowly become more and more
out-of-date.

Make sure your repository is clean (no uncommitted changes) If not, commit or
stash any changes, and do

    $ git fecth upstream

Then you can merge all the new commits from the main line to your `develop`
branch

    $ git checkout develop
    $ git merge upstream/develop

There may be merge conflicts to be manually resolved.

If you need to integrate with another developer but his commits have not yet
been merged upstream just merge his branch directly.

### Something went wrong

Git lets you correct your errors! Depending on the publication status of your
erroneous commits it may be more or less efficient or easy. Easiest to fix
errors are in unpublished commits. Even in your public fork you may correct
the history of changes that are not yet merged into the main repository but it
may take some time. Commits that have already been applied to the main line
and thus are possibly already distributed over many contributor's private
repositories errors can only be fixed by making new commits that revert the
erroneous commit's changes but not by fixing the commit object directly.
[edit] Correcting errors in private unpublished commits

In your private repository you are god. You can completely rewrite the
history, but you shouldn't touch commits that have already been published and
merged into the main repository. Otherwise you will suffer heavily next time
you pull ;) or you cause others a lot of trouble when theiy want to pull from
you.

Exemplary errors and fixes are:

* Forgot something in the last commit --> Amend
* Commited too much, like to split up into multiple commits --> Soft Reset
* Things went so wrong that you want to throw some commits away --> Hard Reset

Note: Before you play god, be careful! If you rewrite history which has
already been pushed remote then you need to force overwriting the remote
history or you won't be able to push again. See correcting errors in your
public repo. If the commits you want to discard have already been propagated
into other's repositories then you will probably cause a lot of trouble!


### Correcting errors in your public remote repository

Yes, git can do that too. But beware, as you can guess, much trouble can be
caused by rewriting history that others have already based their work on. Only
do this, if you are sure that no one has yet pulled the commits you want to
change.

First of all, fix your local repository as described in the previous section.
After that you can force your public repository to the new revision history.
If the public repository is configured to allow forced pushes then simply do:

    git push -f origin master

If the remote repository rejects a forced push there is still a trick, but it
might take a little longer for big repositories (so beware):

    git push origin :master
    git push origin master

To understand what's happening here you should know that push allows to push
from one branch to the other with the following notation
`local_branch:remote_branch`. A normal git push origin master is a shortcut for
git push origin master:master. If you leave the local branch blank it will
delete the remote branch. The second push will then recreate it and transport
your complete rewritten revision history to the remote repository.
[edit] Correcting errors that are already merged upstream

## Normal workflow

### Before start

Make sure you have your fork up-to-date and your working tree is clear.
Suppose this is your local repo

        o---o---o                     master
                 \
                  o---o---o---o       develop
                           \
                            o---o     topic

You can use this command to get the commits from the upstream repo that you
don't have yet

    $ git fetch upstream
    $ git checkout develop
    $ git merge upstream/develop

This should be a fast-forward merge, because if you have not updated, other
developers could send their work in the meantime and `upstream/develop` is
ahead of your `origin/develop` branch.

        o---o---o                                 master
                 \
                  o---o---o---o---o---o---o       develop
                           \
                            o---o                 topic

If you have commits in your `develop` branch that you have not pushed yet, of
that the maintainer has no integrated yet, probably you will obtain a merge
commit and you will have to resolve any conflict that may appear.

        o---o---o                       master
                 \
                  \       o---o---o     upstream/develop
                   \     /         \
                    o---o---o---o---o   develop
                             \
                              o---o     topic

Now that you have the last changes from the [Analyser][analysis-repo] repo,
you can start working.

### Working in a new feature

If you will start to work in some new feature, it is recommended that you use
a topic branch, and do all your work in there:

    $ git checkout -b feature develop

You can commit as recommended until you finish the feature. In the
meantime you can update your `develop` branch with changes in the upstream
repository:

       o---o---o---o---o---o           develop
                    \
                     o---o---o---o     feature


To see the differences between your work and the current state of the
`develop` branch:

    $ git checkout feature
    $ git diff develop

    $ git diff develop feature

To see the differences between the `feature` branch and the merge base between
`develop` and `feature` (this is, all the changes introduced by the commits of
the `feature` branch):

    $ git diff develop...feature

To see all the commits in the `feature` branch since it was created

    $ git diff develop..feature

To see all the new commits in the `develop` branch since you created the
`feature` branch:

    # git log feature..develop

### Rewriting history

TODO.

### Integrating the new feature into your development branch

Now you have finished your work, is time to integrate the changes into the
development line.

    $ git checkout develop
    $ git merge feature

If everything is OK, you will obtain the following:

       o---o---o---o---o---o-------o   develop
                    \             /
                     o---o---o---o     feature

But also you can get conflicts that you will have to resolve before complete
the merge.

You will not use anymore the `feature` branch, so it can be deleted:

    $ git branch -d feature

### Rebasing your work

TODO.

### Publishing your changes

When you consider that your changes are OK and you are convinced of that, and
you followed the coding conventions, your commits introduce logical changes
and the messages are written in a correct form, then it is time to publish
your work.

    $ git push origin develop

You must send a pull request to the maintainer, so they can pull your changes
and introduce them into the blessed repository.

### Keeping your clone up-to-date

Anytime you can get all the new commits from the main line:

    $ git fetch upstream

You can checkout the state of the upstream repo by doing

    $ git checkout upstream/develop

Note that this creates a detached HEAD. You should not commit anything. It is
used only to see what the files look like in the upstream.

You can also see the differences between your local branch and the upstream
branch

    $ git diff develop..upstream/develop

Or use this commands to view history

    $ git log develop..upstream/develop
    $ git log upstream/develop..develop
    $ git log upstream/develop...develop

The first form lists commits that do not appear in the local `develop` but
appear in the `upstream/develop` (that is the `develop` branch at the
`upstream` repository (where you forked from). In other words, they are what
others did.

The second form lists commits that do appear in the local `develop` but do not
appear in the `upstream/develop`. They are what you hare still holding onto
without showing others.

The last one shows both. It is often useful to use with `--left-right` option,
like this:

    $ git log --oneline --graph --left-right upstream/develop...develop

### Solving conflicts

When a merge isn't resolved automatically, git leaves the index and the
working tree in a special state that gives you all the information you need to
help resolve the merge.

    $ git merge feature

    Auto-merging somefile.cxx
    CONFLICT (content): Merge conflict in somefile.cxx
    Automatic merge failed; fix conflicts and then commit the result.

Files with conflicts are marked specially in the index, so until you resolve
the problem and update the index, `git commit` will fail:

    $ git commit

    somfile.cxx: needs merge

Also, `git status` will list those files as *unmerged*, and the files with
conflicts will have conflict markers added, like this:

    <<<<<<< HEAD:somefile.cxx
    TFile *data = new TFile("data_part.root", "RECREATE", "Particles data");
    =======
    TFile *output = new TFile("particle_data.root", "RECREATE", "Data of particles");
    >>>>>>> feature:somefile.cxx

This means the version in `HEAD` (your `develop` branch, because that was what you
had checked out when you ran your merge command) is the top part of that block
(everything above the `=======`), while the version in your `feature` branch looks
like everything in the bottom part. In order to resolve the conflict, you have
to either choose one side or the other or merge the contents yourself.

All you need to do is edit the file to resolve the conflicts by choosing one
part or another, or a little of each section, removing the `<<<<<<<`,
`=======`, and `>>>>>>>` lines and then

    $ git add somefile.cxx

After doing the same for each conflictive file, you can complete the merge

    $ git commit

Note that the commit message will already be filled in for you with some
information about the merge. Normally you can just use this default message
unchanged, but you may add additional commentary of your own if desired.

If you want to use a graphical tool to resolve these issues, you can run `git
mergetool`, which fires up an appropriate visual merge tool and walks you
through the conflicts:

    $ git mergetool
    merge tool candidates: kdiff3 tkdiff xxdiff meld gvimdiff opendiff emerge vimdiff
    Merging the files: somefile.cxx

    Normal merge conflict for 'somefile.cxx':
    {local}: modified
    {remote}: modified
    Hit return to start merge resolution tool (meld):

The recommended option to use is `meld`, that can be easily installed from
repositories on a Debian based distro with

    $ sudo aptitude install meld

If you get stuck and decide to just give up and throw the whole mess away, you
can always return to the pre-merge state with

    $ git reset --hard HEAD

Or, if you've already committed the merge that you want to throw away,

    $ git reset --hard ORIG_HEAD

However, this last command can be dangerous in some cases--never throw away a
commit if that commit may itself have been merged into another branch, as
doing so may confuse further merges.

More information about solving conflicts can be found
[here](http://book.git-scm.com/5_advanced_branching_and_merging.html).

### Bug fixes

TODO.

### Working with other developers

TODO.

# Help

If you need more extensive help, you can see

* <http://git-scm.com>
* <http://help.github.com>
* <http://progit.org/book>
* <http://learn.github.com>
* <http://www.gitready.com>


[analysis-repo]: http://github.com/usm-data-analysis/Analyser "Analyser"
[usm-user]: http://github.com/usm-data-analysis "usm-data-analysis"
[coding]: http://github.com/usm-data-analysis/Analyser/blob/master/doc/coding_conventions.md "Coding Conventions"
[wiki]: http://wiki.github.com/usm-data-analysis/Analyser "Analyser wiki"
[issues]: http://github.com/usm-data-analysis/Analyser/issues "Analyser issues"
