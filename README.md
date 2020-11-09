# Linux Morse - A collection of commands to practice morse

## Usage

`echo 'some text' | morse` → `... --- -- . / - . -..- -`
`echo '... --- -- . / - . -..- -' | unmorse` → `some text`
`echo '... --- -- . / - . -..- -' | morseplay` → Will produce beeps through your speakers
`morseinput` → Will generate morse code from any keypress

## Build & Install

You will need OpenAL to play morse code.

**Arch**

```
sudo pacman -S openal
```

**Ubuntu**

```
sudo apt install libopenal-dev
```


Then, compile using the Makefile

```
make
sudo make install
```

## Licensing

No. You can do what you want with this code.
