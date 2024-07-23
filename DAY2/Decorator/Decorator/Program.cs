// See https://aka.ms/new-console-template for more information
using System.IO.Compression;

Console.WriteLine("Hello, World!");

byte[] arr = new byte[1024 * 1024];

FileStream fs = new FileStream("a.data", FileMode.Create);

GZipStream zip = new GZipStream(fs, CompressionLevel.SmallestSize);

//fs.Write(arr, 0, arr.Length);
zip.Write(arr, 0, arr.Length);

fs.Close();