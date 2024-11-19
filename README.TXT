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