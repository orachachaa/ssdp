
using System.IO.Compression;

byte[] arr = new byte[1024 * 1024]; // 1M 크기

FileStream fs = new FileStream("a.dat", FileMode.Create);

GZipStream zip = new GZipStream(fs, CompressionLevel.SmallestSize);

//fs.Write(arr, 0, arr.Length );
zip.Write(arr, 0, arr.Length);

fs.Close();

// project 이름/bin/debug/net8.0/a.dat 크기 확인
// => 압축 안하면  1M
// => 압축 하면    10byte

