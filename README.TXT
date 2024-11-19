PLEASE MAKE SURE YOU KNOW THE BASIC GIT WORKFLOW.

I will first touch on the setup needed to allow yourself to work within your remote
server, yet still be connected to your GitHub account. The first step is to generate
a SSH key with the command:
    ssh-keygen -t ed25519 -C "username@serveraddress.com"

Make sure you fill in the correct username and especially the remote machine number/address,
for example I always use machine 2, so mine looks like: "f39chen@ubuntu2204-002.cs.student.uwaterloo.ca".
You will be prompted to enter a pathname in which to store your keys. If you do wish
to leave it as the default one, just copy whatever path is within brackets when you
are prompted, before the semicolon. You are then prompted to enter a passkey to access
said file containing your keys. If you do not want a passkey, simply press 'Enter'
each time you are prompted for a passkey setup. This should generate the appropriate
files, but if you are told that no files exist, just create a file named 'id_ed25519'
within your .ssh folder by either using vim or the 'touch' command to create a new
file with the appropriate name, and use the previous ssh-keygen command again.

This command generates a pair of keys. One is private, the other is public. The private
key is stored in ~/.ssh/id_ed25519, while the public one is stored in ~/.ssh/id_ed25519.pub.
MAKE SURE YOUR PRIVATE KEY IS INDEED PRIVATE. To ensure that, use the command:
    chmod 600 ~/.ssh/id_ed25519

If you chose to store your keys in a different file, use the appropriate path name.
This command ensures that the file storing the private key is only accessible by you,
the owner of the file. Next, make your .ssh folder accessible only to yourself as well:
    chmod 700 ~/.ssh

This command ensures that the .ssh folder can only be read and written to by you.

Next, you will have to copy the generate public key to your own GitHub account, such
that GitHub knows that you are accessing your GitHub account through a remote machine.
You will first go into your public key file to copy THE WHOLE FILE CONTENT (should start
with ssh_ed25519, the encryption method I chose to use), or output onto the terminal
the contents of this file to then copy it. Within GitHub, access Settings, SSH and GPG
keys, New SSH key. You can then paste your public key in the big box, and add a title/name
to your new key to help remember that this key is the school's remote machine (to
possibly delete later). To verify that you can access/connect your GitHub account through
the remote server, use:
    ssh -T git@github.com

If your setup is correct, it should prompt you with a welcome message. You can then
clone the repository to your remote machine:
    git clone git@github.com:forrest211/Biquadris246.git

TYPICAL GIT WORKFLOW

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