PLEASE MAKE SURE YOU KNOW THE BASIC GIT WORKFLOW.
The idea is to create a new branch (creating a new branch makes a new branch that is
a copy of the branch you are currently in), work within that branch, commit your changes,
then push them such that another person could review your changes. Try to minize the
changes you make to EXISTENT files, especially changes that completely overhaul a file.
This way, upon reviewing the newly added code/files, it is much easier merging the branch
to the main one. To create a new branch, the command is as follows:
    git branch NEW_BRANCH_NAME

To then switch/go into the new branch:
    git switch NEW_BRANCH_NAME

These are simplified commands, depends on what you wish to commit to the main branch,
or any branch. To add all files in your branch to commit then push later on, do as
follows:
    git add .

To commit:
    git commit -m "PLEASE INCLUDE APPROPRIATE MESSAGE."

When you commit, the changes are only saved in the local repository in which you are
working on, whether it be on your local machine or remote machine. For others to
see the changes/addition of your branch, you must push the branch (more specifically,
you would push whatever you committed previously, not the whole branch necessarily).
Afterwards, others could git pull to update their own local repository (THIS IS WHY
CREATING BRANCHES IS IMPORTANT, TO NOT CONFLICT EASILY WHEN PULLING). To push:
    git push origin BRANCH_NAME_TO_PUSH

A note: 'origin' refers to the remote repository, which you should be able to access
through GitHub, and allows others to then pull the changes made. The branch name
BRANCH_NAME_TO_PUSH could be 'main' as well.