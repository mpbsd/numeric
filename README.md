Numerical Analysis
==================

About
-----

These are the lecture notes of a course on *numerical analysis* at an
introductory level that I taught to undergraduate students at [UFG][]. The
source code is to be taken more seriously than the final PDF. For example,
whenever you see the source code for a C program named `prog.c` in the text,
you should go ahead type `make prog` at the command prompt of a terminal just
opened at the root of this project. If everything went well, you will then find
a binary file named `prog.out` in the `src` folder, that you could then execute
to perform experiments of your own. Edit the source code to your liking,
recompile it, run it and mostly important, have fun!

Assumption
----------

Keep in mind that I do assume that you, like me, is running a GNU/Linux
operating system like [Debian][] or [Arch Linux][], for instance. If you are on
a Windows machine, you could use the [WSL][]. On macOS, you could install the
[Xcode command line tools][] and [MacTeX][] (see [brew.sh][] if you mind using
a package manager).

Software
--------

The required software to compile and execute the code is listed below.

1. [GCC][] and [Make][]:

    Required to compile C code. The acronym `GCC` stands for `GNU C Compiler`
    and although Make is not strictly necessary, you'll find it much easier to 
    follow along these notes if you have it in your system.

    On Debian based systems, these could be installed with:

    ```shell
    $ sudo apt install build-essential
    ```

    On Arch based systems the command would rather be:

    ```shell
    $ sudo pacman -Syu base-devel
    ```

2. [TeX Live][]:

    Required to produce the PDF. TeX Live is a [LaTeX][] distribution commonly
    available on GNU/Linux. On Debian based systems, it could be installed
    with:

    ```shell
    $ sudo apt install texlive-full
    ```

    And, again, if you're on a Arch based system the command would be:

    ```shell
    $ sudo pacman -Syu texlive-most
    ```

You're also going to need a text editor in order to make changes to the code.
Everyone seems to have their own [preferences][], just pick whatever suits you.

Contact
-------

You can write to me at `bezerra <at> ufg.br`. I'll try to answer you ASAP.

[UFG]: https://ufg.br/
[Debian]: https://debian.org/
[Arch Linux]: https://archlinux.org/
[WSL]: https://learn.microsoft.com/pt-br/windows/wsl/install/
[Xcode command line tools]: https://stackoverflow.com/questions/9329243/how-to-install-xcode-command-line-tools/
[MacTeX]: https://tug.org/mactex/
[brew.sh]: https://brew.sh/
[TeX Live]: https://tug.org/texlive/
[LaTeX]: https://latex-project.org/
[GCC]: https://gcc.gnu.org/
[Make]: https://www.gnu.org/software/make/
[preferences]: https://en.wikipedia.org/wiki/Editor_war
