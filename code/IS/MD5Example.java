import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class MD5Example {

    public static String calculateMD5(String text) {
        try {
          
            MessageDigest md = MessageDigest.getInstance("MD5");

            // Update the digest with the bytes of the text
            md.update(text.getBytes());

            // Calculate the MD5 hash
            byte[] digest = md.digest();

            // Convert the byte array to a hexadecimal string
            StringBuilder sb = new StringBuilder();
            for (byte b : digest) {
                sb.append(String.format("%02x", b));
            }
            return sb.toString();
        } catch (NoSuchAlgorithmException e) {
            // Handle NoSuchAlgorithmException
            e.printStackTrace();
            return null;
        }
    }

    public static void main(String[] args) {
        String text = "Hello, world!";
        String md5Hash = calculateMD5(text);
        System.out.println("MD5 Hash of the text: " + md5Hash);
    }
}
