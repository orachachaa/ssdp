
byte[] arr = new byte[1024 * 1024]; // 1M 크기

FileStream fs = new FileStream("a.dat", FileMode.Create);

fs.Write(arr, 0, arr.Length );

fs.Close();



