# FortyTwo_Printf
Ongoing..
Recoded printf.

## Conversion Specifiers in `printf`

1. **Integer Conversions**:
   - **`%d` or `%i`**: Signed decimal integer.
   - **`%u`**: Unsigned decimal integer.
   - **`%o`**: Unsigned octal integer.
   - **`%x`**: Unsigned hexadecimal integer (lowercase).
   - **`%X`**: Unsigned hexadecimal integer (uppercase).

2. **Floating-Point Conversions**:
   - **`%f`**: Decimal floating-point.
   - **`%F`**: Decimal floating-point (uppercase).
   - **`%e`**: Scientific notation (lowercase).
   - **`%E`**: Scientific notation (uppercase).
   - **`%g`**: Use `%e` or `%f` (whichever is shorter).
   - **`%G`**: Use `%E` or `%F` (whichever is shorter).
   - **`%a`**: Hexadecimal floating-point (lowercase).
   - **`%A`**: Hexadecimal floating-point (uppercase).

3. **Character and String Conversions**:
   - **`%c`**: Character.
   - **`%s`**: String.

4. **Pointer Conversions**:
   - **`%p`**: Pointer address.

5. **Special Conversions**:
   - **`%%`**: Literal `%` character.

### Example Usage

Here is an example code snippet demonstrating the use of various conversion specifiers:

```c
#include <stdio.h>

int main() {
    int d = 123;
    unsigned int u = 123;
    int o = 123;
    int x = 123;
    float f = 123.456;
    double e = 123.456;
    char c = 'A';
    char *s = "Hello, World!";
    void *p = &d;

    printf("Signed decimal integer: %d\n", d);
    printf("Unsigned decimal integer: %u\n", u);
    printf("Unsigned octal integer: %o\n", o);
    printf("Unsigned hexadecimal integer (lowercase): %x\n", x);
    printf("Unsigned hexadecimal integer (uppercase): %X\n", x);
    printf("Decimal floating-point: %f\n", f);
    printf("Scientific notation (lowercase): %e\n", e);
    printf("Scientific notation (uppercase): %E\n", e);
    printf("Use %%e or %%f (whichever is shorter): %g\n", e);
    printf("Character: %c\n", c);
    printf("String: %s\n", s);
    printf("Pointer address: %p\n", p);
    printf("Literal %% character: %%\n");

    return 0;
}
```

### Output

```
Signed decimal integer: 123
Unsigned decimal integer: 123
Unsigned octal integer: 173
Unsigned hexadecimal integer (lowercase): 7b
Unsigned hexadecimal integer (uppercase): 7B
Decimal floating-point: 123.456001
Scientific notation (lowercase): 1.234560e+02
Scientific notation (uppercase): 1.234560E+02
Use %e or %f (whichever is shorter): 123.456
Character: A
String: Hello, World!
Pointer address: 0x7ffee4b3c9ac
Literal % character: %
```

## Format Specifiers with Flags

This section provides a summary of the correct and incorrect usages of the `-`, `0`, `#`, ` `, `+`, and `.` flags along with the field width for different conversions in the `printf` function.

### Note on Flag Placement in `printf`

In the `printf` function, all flags must come before the format specifier. The general syntax for a format specifier in `printf` is:
```
%[flags][width][.precision][length]specifier
```

### Explanation of Flags

1. **`.` (Precision)**:
   - For integer conversions (`d`, `i`, `u`, `o`, `x`, `X`): Specifies the minimum number of digits to be printed. If the number of digits is less than the precision, the output is padded with leading zeros.
   - For floating-point conversions (`f`, `F`, `e`, `E`, `g`, `G`): Specifies the number of digits to be printed after the decimal point.
   - For string conversions (`s`): Specifies the maximum number of characters to be printed.

   Examples:
   - `%.5d` with input `123`: `00123`
   - `%.2f` with input `123.456`: `123.46`
   - `%.3s` with input `"hello"`: `hel`

2. **`0` (Pad with zeros)**:
   - Pads the output with leading zeros instead of spaces. This flag is ignored if the `-` flag (left-justify) is also specified.

   Examples:
   - `%010d` with input `123`: `0000000123`
   - `%010.2f` with input `123.45`: `0000123.45`

3. **`-` (Left-justify)**:
   - Left-justifies the output within the specified field width. This flag overrides the `0` flag.

   Examples:
   - `%-10d` with input `123`: `123       `
   - `%-10.2f` with input `123.45`: `123.45    `

4. **Field Width**:
   - Specifies the minimum number of characters to be printed. If the output is shorter than the field width, it is padded with spaces (or zeros if the `0` flag is specified).

   Examples:
   - `%10d` with input `123`: `       123`
   - `%10.2f` with input `123.45`: `    123.45`

5. **`#` (Hash)**:
   - For `o` (octal) conversion: Prefixes the output with `0`.
   - For `x` or `X` (hexadecimal) conversion: Prefixes the output with `0x` or `0X`.
   - For `a`, `A`, `e`, `E`, `f`, `F`, `g`, `G` conversions: Forces the output to contain a decimal point even if no digits follow it.

   Examples:
   - `%#x` with input `123`: `0x7b`
   - `%#o` with input `123`: `0173`
   - `%#f` with input `123.0`: `123.000000`

6. **`+` (Plus)**:
   - For signed numeric conversions (`d`, `i`, `f`, `F`, `e`, `E`, `g`, `G`): Prefixes the output with a `+` sign if the value is positive. This flag overrides the space flag.

   Examples:
   - `%+d` with input `123`: `+123`
   - `%+f` with input `123.45`: `+123.450000`

7. **` ` (Space)**:
   - For signed numeric conversions (`d`, `i`, `f`, `F`, `e`, `E`, `g`, `G`): Prefixes the output with a space if the value is positive and not already prefixed with a sign.

   Examples:
   - `% d` with input `123`: ` 123`
   - `% f` with input `123.45`: ` 123.450000`

8. **`%` (Percent)**:
   - The `%` conversion specifier is used to print a literal `%` character.

### Behavior on Combinations

1. **`0` and `-`**:
   - The `-` flag overrides the `0` flag. If both are specified, the output is left-justified and padded with spaces.

   Example:
   - `%-010d` with input `123`: `123       `

2. **`+` and ` `**:
   - The `+` flag overrides the space flag. If both are specified, the output is prefixed with a `+` sign for positive numbers.

   Example:
   - `%+ d` with input `123`: `+123`

3. **`#` with `o`, `x`, `X`**:
   - The `#` flag prefixes the output with `0` for octal, `0x` for lowercase hexadecimal, and `0X` for uppercase hexadecimal.

   Examples:
   - `%#o` with input `123`: `0173`
   - `%#x` with input `123`: `0x7b`
   - `%#X` with input `123`: `0X7B`

4. **`#` with `f`, `F`, `e`, `E`, `g`, `G`**:
   - The `#` flag forces the output to contain a decimal point even if no digits follow it.

   Examples:
   - `%#f` with input `123.0`: `123.000000`
   - `%#e` with input `123.0`: `1.230000e+02`

### Note on Flag Placement in `printf`

In the `printf` function, all flags must come before the format specifier. The general syntax for a format specifier in `printf` is:
'''
%[flags][width][.precision][length]specifier
'''
Here is a breakdown of the components:

- **`%`**: Indicates the start of a format specifier.
- **`[flags]`**: Optional flags that modify the output format. These include:
  - `-`: Left-justify within the given field width.
  - `0`: Pad with leading zeros.
  - `+`: Prefix positive numbers with a plus sign.
  - ` `: Prefix positive numbers with a space.
  - `#`: Use an alternative form (e.g., `0x` for hex).
- **`[width]`**: Optional field width, specifying the minimum number of characters to be printed.
- **`[.precision]`**: Optional precision, specifying the number of digits after the decimal point for floating-point numbers, or the maximum number of characters for strings.
- **`[length]`**: Optional length modifier (e.g., `l` for `long`).
- **`specifier`**: The type of data to be printed (e.g., `d` for integers, `f` for floating-point numbers, `s` for strings).

### Expanded Examples with All Combinations of Flags

#### Integer Conversions (`%d`, `%i`)

| Format       | Input | Output       | Explanation                                      |
|--------------|-------|--------------|--------------------------------------------------|
| `%10d`       | `123` | `       123` | Right-justified with spaces                      |
| `%-10d`      | `123` | `123       ` | Left-justified with spaces                       |
| `%010d`      | `123` | `0000000123` | Right-justified with zeros                       |
| `%+10d`      | `123` | `       +123`| Right-justified with spaces, prefixed with `+`   |
| `% 10d`      | `123` | `        123`| Right-justified with spaces, prefixed with space |
| `%+010d`     | `123` | `+000000123` | Right-justified with zeros, prefixed with `+`    |
| `% 010d`     | `123` | ` 000000123` | Right-justified with zeros, prefixed with space  |
| `%-+10d`     | `123` | `+123      ` | Left-justified with spaces, prefixed with `+`    |
| `%- 10d`     | `123` | ` 123      ` | Left-justified with spaces, prefixed with space  |
| `%-010d`     | `123` | `123       ` | Left-justified with spaces (ignores `0` flag)    |
| `%-.5d`      | `123` | `00123`      | Precision with leading zeros                     |

#### Unsigned Integer Conversions (`%u`)

| Format       | Input | Output       | Explanation                                      |
|--------------|-------|--------------|--------------------------------------------------|
| `%10u`       | `123` | `       123` | Right-justified with spaces                      |
| `%-10u`      | `123` | `123       ` | Left-justified with spaces                       |
| `%010u`      | `123` | `0000000123` | Right-justified with zeros                       |
| `%-010u`     | `123` | `123       ` | Left-justified with spaces (ignores `0` flag)    |
| `%.5u`       | `123` | `00123`      | Precision with leading zeros                     |

#### Hexadecimal Conversions (`%x`, `%X`)

| Format       | Input | Output       | Explanation                                      |
|--------------|-------|--------------|--------------------------------------------------|
| `%10x`       | `123` | `        7b` | Right-justified with spaces                      |
| `%-10x`      | `123` | `7b        ` | Left-justified with spaces                       |
| `%010x`      | `123` | `000000007b` | Right-justified with zeros                       |
| `%#10x`      | `123` | `      0x7b` | Right-justified with spaces, prefixed with `0x`  |
| `%#010x`     | `123` | `0x0000007b` | Right-justified with zeros, prefixed with `0x`   |
| `%-#10x`     | `123` | `0x7b      ` | Left-justified with spaces, prefixed with `0x`   |
| `%.5x`       | `123` | `0007b`      | Precision with leading zeros                     |

#### Octal Conversions (`%o`)

| Format       | Input | Output       | Explanation                                      |
|--------------|-------|--------------|--------------------------------------------------|
| `%10o`       | `123` | `       173` | Right-justified with spaces                      |
| `%-10o`      | `123` | `173       ` | Left-justified with spaces                       |
| `%010o`      | `123` | `0000000173` | Right-justified with zeros                       |
| `%#10o`      | `123` | `      0173` | Right-justified with spaces, prefixed with `0`   |
| `%#010o`     | `123` | `0000000173` | Right-justified with zeros, prefixed with `0`    |
| `%-#10o`     | `123` | `0173      ` | Left-justified with spaces, prefixed with `0`    |
| `%.5o`       | `123` | `00173`      | Precision with leading zeros                     |

#### Floating-Point Conversions (`%f`, `%F`)

| Format       | Input   | Output         | Explanation                                      |
|--------------|---------|----------------|--------------------------------------------------|
| `%10.2f`     | `123.45`| `    123.45`   | Right-justified with spaces                      |
| `%-10.2f`    | `123.45`| `123.45    `   | Left-justified with spaces                       |
| `%010.2f`    | `123.45`| `0000123.45`   | Right-justified with zeros                       |
| `%+10.2f`    | `123.45`| `   +123.45`   | Right-justified with spaces, prefixed with `+`   |
| `% 10.2f`    | `123.45`| `    123.45`   | Right-justified with spaces, prefixed with space |
| `%+010.2f`   | `123.45`| `+000123.45`   | Right-justified with zeros, prefixed with `+`    |
| `% 010.2f`   | `123.45`| ` 000123.45`   | Right-justified with zeros, prefixed with space  |
| `%-+10.2f`   | `123.45`| `+123.45   `   | Left-justified with spaces, prefixed with `+`    |
| `%- 10.2f`   | `123.45`| ` 123.45   `   | Left-justified with spaces, prefixed with space  |
| `%-010.2f`   | `123.45`| `123.45    `   | Left-justified with spaces (ignores `0` flag)    |
| `%#.2f`      | `123.0` | `123.00`       | Forces decimal point                             |

#### Scientific Notation Conversions (`%e`, `%E`)

| Format       | Input   | Output           | Explanation                                      |
|--------------|---------|------------------|--------------------------------------------------|
| `%10.2e`     | `123.45`| ` 1.23e+02`      | Right-justified with spaces                      |
| `%-10.2e`    | `123.45`| `1.23e+02  `     | Left-justified with spaces                       |
| `%010.2e`    | `123.45`| `01.23e+02`      | Right-justified with zeros                       |
| `%+10.2e`    | `123.45`| `+1.23e+02`      | Right-justified with spaces, prefixed with `+`   |
| `% 10.2e`    | `123.45`| ` 1.23e+02`      | Right-justified with spaces, prefixed with space |
| `%+010.2e`   | `123.45`| `+01.23e+02`     | Right-justified with zeros, prefixed with `+`    |
| `% 010.2e`   | `123.45`| ` 01.23e+02`     | Right-justified with zeros, prefixed with space  |
| `%-+10.2e`   | `123.45`| `+1.23e+02 `     | Left-justified with spaces, prefixed with `+`    |
| `%- 10.2e`   | `123.45`| ` 1.23e+02 `     | Left-justified with spaces, prefixed with space  |
| `%-010.2e`   | `123.45`| `1.23e+02  `     | Left-justified with spaces (ignores `0` flag)    |
| `%#.2e`      | `123.0` | `1.23e+02`       | Forces decimal point                             |

#### General Format Conversions (`%g`, `%G`)

| Format       | Input   | Output           | Explanation                                      |
|--------------|---------|------------------|--------------------------------------------------|
| `%10.2g`     | `123.45`| `      1.2e+02`  | Right-justified with spaces                      |
| `%-10.2g`    | `123.45`| `1.2e+02    `    | Left-justified with spaces                       |
| `%010.2g`    | `123.45`| `000001.2e+02`   | Right-justified with zeros                       |
| `%+10.2g`    | `123.45`| `    +1.2e+02`   | Right-justified with spaces, prefixed with `+`   |
| `% 10.2g`    | `123.45`| `     1.2e+02`   | Right-justified with spaces, prefixed with space |
| `%+010.2g`   | `123.45`| `+00001.2e+02`   | Right-justified with zeros, prefixed with `+`    |
| `% 010.2g`   | `123.45`| ` 00001.2e+02`   | Right-justified with zeros, prefixed with space  |
| `%-+10.2g`   | `123.45`| `+1.2e+02  `     | Left-justified with spaces, prefixed with `+`    |
| `%- 10.2g`   | `123.45`| ` 1.2e+02  `     | Left-justified with spaces, prefixed with space  |
| `%-010.2g`   | `123.45`| `1.2e+02    `    | Left-justified with spaces (ignores `0` flag)    |
| `%#.2g`      | `123.0` | `1.2e+02`        | Forces decimal point                             |

#### String Conversions (`%s`)

| Format       | Input     | Output       | Explanation                                      |
|--------------|-----------|--------------|--------------------------------------------------|
| `%10s`       | `"hello"` | `     hello` | Right-justified with spaces                      |
| `%-10s`      | `"hello"` | `hello     ` | Left-justified with spaces                       |
| `%.5s`       | `"hello"` | `hello`      | Precision with max characters                    |
| `%.3s`       | `"hello"` | `hel`        | Precision with max characters                    |

#### Character Conversions (`%c`)

| Format       | Input | Output       | Explanation                                      |
|--------------|-------|--------------|--------------------------------------------------|
| `%5c`        | `'a'` | `    a`      | Right-justified with spaces                      |
| `%-5c`       | `'a'` | `a    `      | Left-justified with spaces                       |

#### `%` Conversion Specifier with Flags

| Format       | Input | Output       | Explanation                                      |
|--------------|-------|--------------|--------------------------------------------------|
| `%5%`        | N/A   | `    %`      | Right-justified with spaces                      |
| `%-5%`       | N/A   | `%    `      | Left-justified with spaces                       |
| `%05%`       | N/A   | `    %`      | Right-justified with spaces, `0` flag ignored    |
| `%-05%`      | N/A   | `%    `      | Left-justified with spaces, `0` flag ignored     |
| `%.5%`       | N/A   | `%`          | Precision ignored                                |
| `%#%`        | N/A   | `%`          | Hash flag ignored                                |
| `%+%`        | N/A   | `%`          | Plus flag ignored                                |
| `% %`        | N/A   | `%`          | Space flag ignored                               |


### Explanation of Incorrect Usages

- **`%0-10d`**: Using both `0` and `-` flags together is incorrect. The `-` flag overrides the `0` flag, so the `0` flag is ignored.
- **`%-010d`**: Same as above, the `0` flag is ignored when `-` is present.
- **`%-.5d`**: The `-` flag does not affect the precision specifier, so this usage is redundant but not incorrect in terms of output.
- **`%0-10.2f`**: Using both `0` and `-` flags together is incorrect. The `-` flag overrides the `0` flag, so the `0` flag is ignored.
- **`%-010.2f`**: Same as above, the `0` flag is ignored when `-` is present.
- **`%0-10s`**: The `0` flag is not applicable to strings, so it is ignored.
- **`%0-5c`**: The `0` flag is not applicable to characters, so it is ignored.
