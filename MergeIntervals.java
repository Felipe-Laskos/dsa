import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class MergeIntervals {
    public static void main(String[] args) {
        ArrayList<List<Integer>> intervals = new ArrayList<>();
        intervals.add(new ArrayList<>(List.of(1, 3)));
        intervals.add(new ArrayList<>(List.of(2, 6)));
        intervals.add(new ArrayList<>(List.of(8, 10)));
        intervals.add(new ArrayList<>(List.of(15, 18)));

        System.out.println();

        execute(intervals).forEach(arr -> {
            System.out.print(" [" + arr.get(0) + ", " + arr.get(1) + "] ");
        });

        System.out.println();
    }

    public static ArrayList<List<Integer>> execute(ArrayList<List<Integer>> intervals) {
        ArrayList<List<Integer>> m = new ArrayList<>();

        intervals.sort(new Comparator<List<Integer>>() {
            @Override
            public int compare(List<Integer> l1, List<Integer> l2) {
                if (l1.get(0) < l2.get(0)) return -1;
                if (l1.get(0) == l2.get(0)) return 0;
                return 1;
            }
        });

        int x = -1;
        
        m.add(intervals.get(0));

        x += 1;

        for(int i = 1; i < intervals.size(); i++) {
            int first = intervals.get(i).get(0);
            int second = intervals.get(i).get(1);

            if (first > m.get(x).get(1)) {
                m.add(intervals.get(i));
                x += 1;
            } else if (second > m.get(x).get(1)) {
                m.get(x).set(1, second);
            }

            if (first < m.get(x).get(0) && second >= m.get(x).get(1)) {
                m.get(x).set(0, first);
            } else if (second < m.get(x).get(0)) {
                m.addFirst(intervals.get(i));
                x += 1;
            }
        }

        return m;
    }
}
