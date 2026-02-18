; ModuleID = '2.ll'
source_filename = "2.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@.str = private unnamed_addr constant [28 x i8] c"arr[0] = %d, arr[n-1] = %d\0A\00", align 1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %3 = alloca [1000 x i32], align 16
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  store i32 0, ptr %1, align 4
  store i32 1000, ptr %2, align 4
  store i32 7, ptr %4, align 4
  store i32 3, ptr %5, align 4
  store i32 0, ptr %6, align 4
  store i32 0, ptr %7, align 4
  %9 = load i32, ptr %4, align 4
  %10 = mul nsw i32 5, %9
  %11 = load i32, ptr %5, align 4
  %12 = mul nsw i32 2, %11
  %13 = sub nsw i32 %10, %12
  %14 = load i32, ptr %5, align 4
  %15 = load i32, ptr %4, align 4
  %16 = mul nsw i32 %14, %15
  br label %17

17:                                               ; preds = %23, %0
  %18 = load i32, ptr %7, align 4
  %19 = icmp slt i32 %18, %13
  br i1 %19, label %20, label %26

20:                                               ; preds = %17
  %21 = load i32, ptr %6, align 4
  %22 = add nsw i32 %21, %16
  store i32 %22, ptr %6, align 4
  br label %23

23:                                               ; preds = %20
  %24 = load i32, ptr %7, align 4
  %25 = add nsw i32 %24, 1
  store i32 %25, ptr %7, align 4
  br label %17, !llvm.loop !6

26:                                               ; preds = %17
  store i32 0, ptr %8, align 4
  %27 = load i32, ptr %2, align 4
  %28 = load i32, ptr %4, align 4
  %29 = load i32, ptr %5, align 4
  %30 = add nsw i32 %28, %29
  %31 = load i32, ptr %6, align 4
  %32 = add nsw i32 %30, %31
  br label %33

33:                                               ; preds = %42, %26
  %34 = load i32, ptr %8, align 4
  %35 = icmp slt i32 %34, %27
  br i1 %35, label %36, label %45

36:                                               ; preds = %33
  %37 = load i32, ptr %8, align 4
  %38 = mul nsw i32 %37, %32
  %39 = load i32, ptr %8, align 4
  %40 = sext i32 %39 to i64
  %41 = getelementptr inbounds [1000 x i32], ptr %3, i64 0, i64 %40
  store i32 %38, ptr %41, align 4
  br label %42

42:                                               ; preds = %36
  %43 = load i32, ptr %8, align 4
  %44 = add nsw i32 %43, 1
  store i32 %44, ptr %8, align 4
  br label %33, !llvm.loop !8

45:                                               ; preds = %33
  %46 = getelementptr inbounds [1000 x i32], ptr %3, i64 0, i64 0
  %47 = load i32, ptr %46, align 16
  %48 = load i32, ptr %2, align 4
  %49 = sub nsw i32 %48, 1
  %50 = sext i32 %49 to i64
  %51 = getelementptr inbounds [1000 x i32], ptr %3, i64 0, i64 %50
  %52 = load i32, ptr %51, align 4
  %53 = call i32 (ptr, ...) @printf(ptr noundef @.str, i32 noundef %47, i32 noundef %52)
  ret i32 0
}

declare i32 @printf(ptr noundef, ...) #1

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"clang version 17.0.0"}
!6 = distinct !{!6, !7}
!7 = !{!"llvm.loop.mustprogress"}
!8 = distinct !{!8, !7}
