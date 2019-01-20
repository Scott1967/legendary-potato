# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

Google says this is an invented long word said to mean a lung disease caused by inhaling very fine ash and sand dust.
Plus it has 45 letters which is the longest word allowed in our speller.c dictionary.

## According to its man page, what does `getrusage` do?

It returns resource usage statistics.

## Per that same man page, how many members are in a variable of type `struct rusage`?

There are 16 members.

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?
        I had to Google this answer because I am doing the online course and didn't learn this.

        Passing large structs by value is slow and takes up a lot of memory.
        If you're passing or returning structs by value, copies of those structs will get placed on the stack.
        This can potentially cause stack overflow.

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.
        I had to Google this answer because I am doing the online course and didn't learn this.

        The key aspect of the for loop is the c = fgetc(fp) function call. fgetc
        gets the next character (an unsigned char) from fp and advances the
        position indicator in fp until the end of the file (EOF) is reached. As
        each character is received, it is put through an if(if)-elseif-elseif
        logical sequence. Summarizing the sequence: 1) If the character is an
        alphabetical character or an apostrophe that is not at index 0 of the
        word, the character is appended to the word array. 2) Else if the
        character is numerical, the word is ignored and we skip ahead to the
        next word (which is found after a space). 3) Else if we hit a space or
        punctuation, we must have found a whole word so we terminate the word by
        adding \0 to the word array.

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?
        I had to Google this answer because I am doing the online course and didn't learn this.

        fscanf with a format string like "%s" will read subsequent characters
        until a whitespace is found (whitespace characters are considered to be
        blank, newline and tab). Because words within the txt files sometimes
        end with punctuation, fscanf will view them as being part of the word,
        which complicates the reading procedure. In addition, if a longer string
        than expected was read using fscanf (e.g. a jibberish string like asdfba
        asdkdfawemflkasciaoeufalkesfasldkfjaoiwefjaslkdmcalksdfiwoefalskdfamsdcl
        asdflkasdlkmceaasdfasdf..., which could be included in a text file from
        a malicious source that is trying to break our program), we could
        overwrite important data in memory or cause a segmentation fault.

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?
        I had to Google this answer because I am doing the online course and didn't learn this.

        With const char* parameter, we prevent changes to the string that
        parameter is pointing at through parameter (i.e. const pointers prevent
        changing the data pointed to)/ The parameters for check (const char* word)
        and load (const char* dictionary) are declared as const pointers because
        we want to prevent changes to a read word and the dictionary we are using.
