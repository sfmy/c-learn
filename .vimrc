set nocompatible              " be iMproved, required
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'

" The following are examples of different formats supported.
" Keep Plugin commands between vundle#begin/end.
" plugin on GitHub repo
" Plugin 'tpope/vim-fugitive'
" plugin from http://vim-scripts.org/vim/scripts.html
" Plugin 'L9'
Plugin 	'The-NERD-tree'
Plugin 	'The-NERD-Commenter'
Plugin  'Tabular'
Plugin  'kien/ctrlp.vim'
" Plugin  'https://github.com/suan/vim-instant-markdown.git'
" Plugin  'https://github.com/idanarye/vim-vebugger'
" Plugin  'https://github.com/isRuslan/vim-es6.git'
Plugin  'Syntastic'
" Plugin  'minibufexpl.vim'
Plugin  'molokai'
Plugin  'jshint.vim'
" Plugin  'moll/vim-node'
" Git plugin not hosted on GitHub
" Plugin 'git://git.wincent.com/command-t.git'
" git repos on your local machine (i.e. when working on your own plugin)
" Plugin 'file:///home/gmarik/path/to/plugin'
" The sparkup vim script is in a subdirectory of this repo called vim.
" Pass the path to set the runtimepath properly.
" Plugin 'rstacruz/sparkup', {'rtp': 'vim/'}
" Install L9 and avoid a Naming conflict if you've already installed a
" different version somewhere else.
" Plugin 'ascenator/L9', {'name': 'newL9'}

" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required
" To ignore plugin indent changes, instead use:
"filetype plugin on
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line

set nu
set autoindent
set hlsearch
set sw=4
set ts=4
set foldmethod=indent
colorscheme molokai
syntax on

set fileencodings=utf-8,ucs-bom,gb18030,gbk,gb2312,cp936
set termencoding=utf-8
set encoding=utf-8

set t_Co=256

let NERDTreeIgnore=[ '\.o$', '\.so$', '\.meta$' ]

let g:instant_markdown_slow = 1
let NERDSpaceDelims=1

let g:ctrlp_custom_ignore = {
    \ 'dir': '\v[\/](doc|temp|node_modules)',
    \ 'file': '\v\.(exe|so|dll|meta)$',
    \ }
