===================================================
Conservative JSON Stream Parser (and maybe Emitter)
===================================================

.. warning::

    NOT YET IMPLEMENTED

.. note::

    Note that `ayqu` is an auto-generated easily search-replacable
    placeholder for a library name which will change as soon as I come
    up with something good.

Goals
=====

* Callback-based asynchronous parsing.
* 100% portable code (C11?).
* No unnecessary performance overhead.
* Low footprint and low memory consumption.
* I/O Independent.
* JSON value type system independent.
* Concatenated JSON support.

TODO
====

* Should I rename ayqu_create to ayqu_create_stream?
* Make sure that ayqu_option can only be called only between ayqu_create and ayqu_feed.
