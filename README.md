Numeric Analysis
================

About
-----

This is where I keep my class notes on a course about *numeric analysis* taught
to grad students at [Universidade Federal de Goiás][]. The material is meant to
serve as an introduction. Also, the source code is to be taken more seriously
than the final PDF. For example, whenever you see the source code for a C
program named `prog.c` in the text, you should probably type `make prog` at the
command prompt of a terminal just opened at the root of this project. If
everything went well, you will then find a binary file named `prog.out` lying
in the `src` folder, that you could then execute to perform experiments of your
own. Edit the source code to your liking, recompile it, rerun it, have fun!

Assumption
----------

Keep in mind that I do assume you to be running a GNU/Linux operating system
like [Debian][] or [Arch Linux][], for instance. The required software to
compile and run the code is listed below:

Software
--------

The required software to compile and execute the code is listed below.

1. [GCC][] and [Make][]:

    Required to compile C code. The acronym `GCC` stands for `GNU C Compiler`
    and although Make is not strictly necessary, you'll find it much easier to 
    follow along these notes if you have it in your system.

    On Debian based systems, these could be installed with:

    > ```shell
    > $ sudo apt install build-essential
    > ```

    On Arch based systems the command would rather be:

    > ```shell
    > $ sudo pacman -Syu base-devel
    > ```

2. [TeX Live][]:

    Required to produce the PDF. TeX Live is a [LaTeX][] distribution commonly
    available on GNU/Linux. On Debian based systems, it could be installed
    with:

    > ```shell
    > $ sudo apt install texlive-full
    > ```

    Again, if you're on a Arch based system, the command would be:

    > ```shell
    > $ sudo pacman -Syu texlive-most
    > ```

You're also going to need a text editor in order to make changes to the code.
Everyone seems to have their own [preferences][], just pick whatever suits you
best.

Contact
-------

You can write to me at `bezerra <at> ufg.br`. I'll try to answer you ASAP.

[Universidade Federal de Goiás]: https://ufg.br/
[Debian]: https://debian.org/
[Arch Linux]: https://archlinux.org/
[TeX Live]: https://tug.org/texlive/
[LaTeX]: https://latex-project.org/
[GCC]: https://gcc.gnu.org/
[Make]: https://www.gnu.org/software/make/
[preferences]: https://en.wikipedia.org/wiki/Editor_war/
