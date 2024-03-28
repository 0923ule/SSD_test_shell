# SSD_test_shell
SSD Test Shell은 SSD의 읽기 및 쓰기 작업을 테스트하기 위한 명령어 기반 쉘 프로그램입니다.

사용자는 간단한 명령어를 통해 특정 블록에 데이터를 쓰거나, 데이터를 읽어볼 수 있습니다.

## Contributors

강형남 (sunkk8482), 이가은 (0923ule)

## Getting started

이 섹션에서는 SSD Test Shell을 로컬 컴퓨터에서 실행하기 위한 지침을 제공합니다.

### Requirments

SSD Test Shell을 실행하기 위해서는 다음이 필요합니다:

- C 컴파일러 (gcc 또는 clang)
- make (옵션)

### Installation

SSD Test Shell을 설치하고 실행하기 위한 단계별 가이드입니다.

1. GitHub에서 저장소를 클론합니다.
```bash
git clone https://github.com/0923ule/ssd_test_shell.git
```
2. 프로그램을 컴파일합니다.
```bash
cd ssd_test_shell
make
```
3. 실행 파일을 시작합니다.
```bash
./testshell
```
## Available Commands

SSD Test Shell에서 사용할 수 있는 명령어는 다음과 같습니다:

- `exit`: 프로그램을 종료합니다.
- `help`: 사용 가능한 명령어들과 그 설명을 표시합니다.
- `write <block> <data>`: 지정된 블록에 데이터를 쓰기 위해 사용합니다. `<block>`은 쓰기를 원하는 블록의 번호이며 숫자여야 합니다. `<data>`는 블록에 쓸 데이터로, 0x로 시작하는 8자리 16진수여야 합니다.
- `read <block>`: 지정된 블록에서 데이터를 읽기 위해 사용합니다. `<block>`은 읽기를 원하는 블록의 번호이며 숫자여야 합니다.
- `fullwrite <data>`: 모든 블록에 동일한 데이터를 쓰기 위해 사용합니다. 총 100번의 쓰기 작업을 수행합니다. `<data>`는 모든 블록에 쓸 데이터로, 0x로 시작하는 8자리 16진수여야 합니다.
- `fullread`: 모든 블록에서 데이터를 읽기 위해 사용합니다. 총 100번의 읽기 작업을 수행하고, 결과를 'result.txt' 파일에 저장합니다.


