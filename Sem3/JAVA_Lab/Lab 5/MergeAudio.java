import javax.sound.sampled.*;
import java.io.File;
import java.util.Scanner;

public class MergeAudio{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        try {
            System.out.println("Enter first audio file parth:");
            String file1 = sc.nextLine();

            System.out.println("Enter second audio file parth:");
            String file2 = sc.nextLine();

            System.out.println("Enter output audio file parth:");
            String output = sc.nextLine();

            AudioInputStream audio1 = AudioSystem.getAudioInputStream(new File(file1));
            AudioInputStream audio2 = AudioSystem.getAudioInputStream(new File(file2));

            AudioFormat format1 = audio1.getFormat();
            AudioFormat format2 = audio2.getFormat(); 

            if(!format1.matches(format2)){
                System.out.println("Error: file format is not same");
                audio1.close();
                audio2.close();
                sc.close();
                return;
            }

            AudioInputStream mergAudio = 
                new AudioInputStream(
                    new java.io.SequenceInputStream(audio1,audio2), 
                    format1,
                    audio1.getFrameLength() + audio2.getFrameLength()
                );
            
            AudioSystem.write(
                mergAudio,
                AudioFileFormat.Type.WAVE,
                new File(output)
            );

            System.out.println("Audio File merged");

            mergAudio.close();
            audio1.close();
            audio2.close();
            sc.close();
        } catch (Exception e) {
            System.out.println("Error:" + e.getMessage());
        }
    }
}