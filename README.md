# io-cxx-concepts
C++20 Concepts using Writer and Reader IO Templates


## C++20 Concepts vs Rust Trait Bounds
C++20 introduces Concepts to constrain C++ template parameter types in templates to a specific
interface signature that Rust Traits do using `Trait Bounds`.` C++20 Concepts constrain any template type parameter T
that does NOT provide the specificed concepts signature to fail during compile.

C++ Concepts.

```c++
#include <concepts>
#include <cstddef>

template<typename T>
concept Writer = requires(T writer, const char* data, std::size_t size) {
    { writer.write(data, size) } -> std::same_as<void>;
};

template<typename T>
concept Reader = requires(T reader, char* buffer, std::size_t size) {
    { reader.read(buffer, size) } -> std::convertible_to<std::size_t>;
};

template<Writer W, Reader R>
void processData(W& writer, R& reader) {
    char buffer[1024];
    std::size_t bytesRead = reader.read(buffer, sizeof(buffer));
    writer.write(buffer, bytesRead);
}
```


The Rust equivalent.

```rust
use std::io::{Read, Write};

fn process_data<W: Write, R: Read>(writer: &mut W, reader: &mut R) -> std::io::Result<()> {
    let mut buffer = [0; 1024];
    let bytes_read = reader.read(&mut buffer)?;
    writer.write_all(&buffer[..bytes_read])?;
    Ok(())
}
```
